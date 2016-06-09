#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QCursor>
#include <QPoint>

int pigKilled_count = 0;
int totalbird = 4;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clicked_tag = 0;
    moved_tag = 0;
    bird_count = 0;


    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/image/background.png").scaled(970,550));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    buttons[0] = new Button(QPixmap(":/image/replaybutton_new.png"),780,13,scene);
    buttons[1] = new Button(QPixmap(":/image/exitbutton_new.png"),850,12,scene);
    buttonList.push_back(buttons[0]);
    buttonList.push_back(buttons[1]);

    // Create bird (You can edit here)
    slingshot = new SlingShot(4.66667f,5.83333f,3.33333f,5.0f,&timer,QPixmap(":/image/slingshot.png").scaled(width()/9,height()/3.3),world,scene);
    itemList.push_back(slingshot);

    score = new Score(world,scene);
    itemList.push_back(score);

    spawn();

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    connect(this,SIGNAL(restartGame()),this,SLOT(RESTARTSLOT()));
    timer.start(100/6);
}


bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if((mouseEvent->button() == Qt::LeftButton) ){


                QPoint p = QCursor::pos();
                real_init_Pos = mapFromGlobal(p);

                QPoint init_Pos;
                init_Pos.setX(140);
                init_Pos.setY(270);

                //std::cout << "x= " << real_init_Pos.x() << std::endl ;
                //std::cout << "y= " << real_init_Pos.y() << std::endl ;

                if( ( (real_init_Pos.x()>855) && (real_init_Pos.x() < 905) ) &&( (real_init_Pos.y()> 20) && (real_init_Pos.y()< 65) ) ){
                                std::cout << "END GAME" << std::endl;
                                emit quitGame();

                }

                if( ( (real_init_Pos.x()>785) && (real_init_Pos.x() < 835) ) &&( (real_init_Pos.y()> 20) && (real_init_Pos.y()< 65) ) ){
                                std::cout << "RESTART GAME" << std::endl;
                                emit restartGame();
                }

            if(totalbird != 0){
                if( real_init_Pos.x()>240 || real_init_Pos.x()<130 || real_init_Pos.y()<260 || real_init_Pos.y() >340 ){
                    clicked_tag = 0;
                }
                else if( ( real_init_Pos.x()>130 && real_init_Pos.x()<240 ) && (real_init_Pos.y()>260 && real_init_Pos.y() <340)){
                    clicked_tag = 1;
                    currentBird->g_body->SetType(b2_staticBody);
                    currentBird->setTransform(init_Pos);
                }
            }
        }


            if(totalbird != 0){
                if( (mouseEvent->button() == Qt::RightButton) && (flyBird->usedSkill_tag == 0)){

                    flyBird->useSkills();
                    flyBird->usedSkill_tag =1;
                }
            }
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        if(totalbird != 0){
            if(clicked_tag == 1){
                    QPoint p = QCursor::pos();
                    real_moved_Pos = mapFromGlobal(p);

                    QPoint moved_Pos;
                    moved_Pos.setX(real_moved_Pos.x() -real_init_Pos.x() + 140);
                    moved_Pos.setY(real_moved_Pos.y() - real_init_Pos.y() + 270);
                    currentBird->setTransform(moved_Pos);
                    moved_tag = 1;
            }
        }

        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);


        if(mouseEvent->button() == Qt::LeftButton){

            /* TODO : add your code here */
                clicked_tag = 0;
                slingshot->g_body->SetActive(0);
            if(totalbird!=0){
                if(moved_tag == 1){

                    float vec_x = (real_init_Pos.x() - real_moved_Pos.x() ) /10;
                    float vec_y = -(real_init_Pos.y() - real_moved_Pos.y() ) /10;

                    currentBird->g_body->SetType(b2_dynamicBody);
                    currentBird->setLinearVelocity(b2Vec2(vec_x,vec_y));

                    currentBird->flyed_tag =1;
                    flyBird = currentBird;


                    vec_x = 0;
                    vec_y = 0;

                    if(bird_count <3){
                    bird_count++;
                    currentBird = birdie[bird_count];
                    }
                }

                moved_tag = 0;
            }
        }

    }

    return false;
}

void MainWindow::spawn()
{
    birdie[0] = new redBird(4.66667f,8.3f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie[1] = new yellowBird(2.5f,4.8f,0.27f,&timer,QPixmap(":/image/yellowbird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie[2] = new blackBird(1.5f,4.8f,0.27f,&timer,QPixmap(":/image/blackbird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie[3] = new greenBird(0.3f,4.7f,0.27f,&timer,QPixmap(":/image/greenbird.png").scaled(height()/9.0,height()/9.0),world,scene);

    bricks[0] = new woodBrick_ver(19.5f,5.5f,-1.5f,1.0f,&timer,QPixmap(":/image/block_vert.png").scaled(width()/50,height()/4.5),world,scene);
    bricks[1] = new woodBrick_ver(23.0f,5.5f,-1.5f,1.0f,&timer,QPixmap(":/image/block_vert.png").scaled(width()/50,height()/4.5),world,scene);
    bricks[2] = new woodBrick_ver(26.5f,5.5f,-1.5f,1.0f,&timer,QPixmap(":/image/block_vert.png").scaled(width()/50,height()/4.5),world,scene);
    bricks[3] = new iceBrick_vert(26.5f,5.5f,-1.5f,1.0f,&timer,QPixmap(":/image/iceblock_vert.png").scaled(width()/50,height()/4.5),world,scene);
    bricks[4] = new iceBrick_vert(26.5f,5.5f,-1.5f,1.0f,&timer,QPixmap(":/image/iceblock_vert.png").scaled(width()/50,height()/4.5),world,scene);
    bricks[5] = new stoneBrick_ver(21.25f,11.0f,-1.5f,1.0f,&timer,QPixmap(":/image/stoneblock_vert.png").scaled(width()/50,height()/4.5),world,scene);
    bricks[6] = new stoneBrick_ver(24.75f,11.0f,-1.5f,1.0f,&timer,QPixmap(":/image/stoneblock_vert.png").scaled(width()/50,height()/4.5),world,scene);
    bricks[7] = new woodBrick_ver(26.5f,5.5f,-1.5f,1.0f,&timer,QPixmap(":/image/block_vert.png").scaled(width()/50,height()/4.5),world,scene);

    pigs[0] = new normalPig(21.0f,5.5f,0.3f,&timer,QPixmap(":/image/pig.png").scaled(height()/10.0,height()/10.0),world,scene);
    pigs[1] = new normalPig(24.5f,5.5f,0.3f,&timer,QPixmap(":/image/pig.png").scaled(height()/10.0,height()/10.0),world,scene);
    pigs[2] = new normalPig(22.90f,10.0f,0.3f,&timer,QPixmap(":/image/pig.png").scaled(height()/10.0,height()/10.0),world,scene);


    itemList.push_back(birdie[0]);
    itemList.push_back(birdie[1]);
    itemList.push_back(birdie[2]);
    itemList.push_back(birdie[3]);

    itemList.push_back(bricks[0]);
    itemList.push_back(bricks[1]);
    itemList.push_back(bricks[2]);
    itemList.push_back(bricks[3]);
    itemList.push_back(bricks[4]);
    itemList.push_back(bricks[5]);
    itemList.push_back(bricks[6]);
    itemList.push_back(bricks[7]);

    itemList.push_back(pigs[0]);
    itemList.push_back(pigs[1]);
    itemList.push_back(pigs[2]);

    bricks[3]->g_body->SetTransform(b2Vec2(21.25f,10.0f),1.5708);
    bricks[4]->g_body->SetTransform(b2Vec2(24.75f,10.0f),1.5708);
    bricks[7]->g_body->SetTransform(b2Vec2(23.0f,15.0f),1.5708);

    currentBird = birdie[0];
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}


void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();

    //std::cout << "pigKilled = " << pigKilled_count << std::endl;

}


void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
    qApp->exit();
}

void MainWindow::RESTARTSLOT()
{
    std::cout << "RESTARTING" << std::endl;
    //totalbird = 0;

    if(totalbird != 0){

        birdie[0]->g_body->SetTransform(b2Vec2(4.66667f,8.3f),0);
        birdie[0]->g_body->SetType(b2_staticBody);
        birdie[0]->usedSkill_tag = 0;
        birdie[1]->g_body->SetTransform(b2Vec2(2.5f,4.8f),0);
        birdie[1]->g_body->SetType(b2_staticBody);
        birdie[1]->usedSkill_tag = 0;
        birdie[2]->g_body->SetTransform(b2Vec2(1.5f,4.8f),0);
        birdie[2]->g_body->SetType(b2_staticBody);
        birdie[2]->usedSkill_tag = 0;
        birdie[3]->g_body->SetTransform(b2Vec2(0.3f,4.7f),0);
        birdie[3]->g_body->SetType(b2_staticBody);
        birdie[3]->usedSkill_tag = 0;

        currentBird = birdie[0];
        bird_count = 0;

        bricks[0]->g_body->SetLinearVelocity(b2Vec2(0,0));
        bricks[0]->g_body->SetTransform(b2Vec2(19.5f,5.5f),0);
        bricks[1]->g_body->SetLinearVelocity(b2Vec2(0,0));
        bricks[1]->g_body->SetTransform(b2Vec2(23.0f,5.5f),0);
        bricks[2]->g_body->SetLinearVelocity(b2Vec2(0,0));
        bricks[2]->g_body->SetTransform(b2Vec2(26.5f,5.5f),0);
        bricks[3]->g_body->SetLinearVelocity(b2Vec2(0,0));
        bricks[3]->g_body->SetTransform(b2Vec2(21.25f,10.0f),1.5708);
        bricks[4]->g_body->SetLinearVelocity(b2Vec2(0,0));
        bricks[4]->g_body->SetTransform(b2Vec2(24.75f,10.0f),1.5708);
        bricks[5]->g_body->SetLinearVelocity(b2Vec2(0,0));
        bricks[5]->g_body->SetTransform(b2Vec2(21.25f,11.0f),0);
        bricks[6]->g_body->SetLinearVelocity(b2Vec2(0,0));
        bricks[6]->g_body->SetTransform(b2Vec2(24.75f,11.0f),0);
        bricks[7]->g_body->SetLinearVelocity(b2Vec2(0,0));
        bricks[7]->g_body->SetTransform(b2Vec2(23.0f,15.0f),1.5708);


        pigs[0]->g_body->SetLinearVelocity(b2Vec2(0,0));
        pigs[0]->g_body->SetTransform(b2Vec2(21.0f,4.65f),0);
        pigs[0]->removed_tag = 0;
        pigs[1]->g_body->SetLinearVelocity(b2Vec2(0,0));
        pigs[1]->g_body->SetTransform(b2Vec2(24.5f,4.65f),0);
        pigs[1]->removed_tag = 0;
        pigs[2]->g_body->SetLinearVelocity(b2Vec2(0,0));
        pigs[2]->g_body->SetTransform(b2Vec2(22.90f,10.0f),0);
        pigs[2]->removed_tag = 0;

        pigKilled_count = 0;


    }


    //currentBird = NULL;
    //flyBird = NULL;
}
