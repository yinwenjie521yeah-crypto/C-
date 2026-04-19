#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    // 战斗界面先隐藏
    ui->label_player->hide();
    ui->label_enemy->hide();
    ui->progressBar_player->hide();
    ui->progressBar_enemy->hide();
    ui->textEdit_log->hide();
    ui->pushButton_skill1->hide();
    ui->pushButton_skill2->hide();
    ui->pushButton_skill3->hide();
    ui->pushButton_back->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("请选择角色");

    ui->pushButton->hide();      // 开始游戏隐藏
    ui->pushButton_2->hide();    // 退出游戏隐藏

    ui->pushButton_3->show();    // 张楚岚显示
    ui->pushButton_4->show();    // 冯宝宝显示

}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText("战斗中");
    ui->pushButton_back->show();

    // 隐藏角色选择按钮
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();

    // 显示战斗界面
    ui->label_player->show();
    ui->label_enemy->show();
    ui->progressBar_player->show();
    ui->progressBar_enemy->show();
    ui->textEdit_log->show();
    ui->pushButton_skill1->show();
    ui->pushButton_skill2->show();
    ui->pushButton_skill3->show();

    // 设置人物信息
    ui->label_player->setText("张楚岚");
    ui->label_enemy->setText("冯宝宝");

    ui->progressBar_player->setValue(100);
    ui->progressBar_enemy->setValue(100);

    ui->pushButton_skill1->setText("掌心雷");
    ui->pushButton_skill2->setText("阳五雷");
    ui->pushButton_skill3->setText("迅雷");

    ui->textEdit_log->clear();
    ui->textEdit_log->append("张楚岚出战！");
    ui->textEdit_log->append("对手是冯宝宝！");
    isPlayerZhang = true;
    playerHp = 100;
    enemyHp = 100;
    updateBattleUI();

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->label->setText("战斗中");
    ui->pushButton_back->show();

    // 隐藏角色选择按钮
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();

    // 显示战斗界面
    ui->label_player->show();
    ui->label_enemy->show();
    ui->progressBar_player->show();
    ui->progressBar_enemy->show();
    ui->textEdit_log->show();
    ui->pushButton_skill1->show();
    ui->pushButton_skill2->show();
    ui->pushButton_skill3->show();

    // 设置人物信息
    ui->label_player->setText("冯宝宝");
    ui->label_enemy->setText("张楚岚");

    ui->progressBar_player->setValue(100);
    ui->progressBar_enemy->setValue(100);

    ui->pushButton_skill1->setText("菜刀斩");
    ui->pushButton_skill2->setText("回血");
    ui->pushButton_skill3->setText("认真一刀");

    ui->textEdit_log->clear();
    ui->textEdit_log->append("冯宝宝出战！");
    ui->textEdit_log->append("对手是张楚岚！");
    isPlayerZhang = false;
    playerHp = 100;
    enemyHp = 100;
    updateBattleUI();
}



    void MainWindow::updateBattleUI()
{
    ui->progressBar_player->setValue(playerHp);
    ui->progressBar_enemy->setValue(enemyHp);
}
void MainWindow::on_pushButton_5_clicked()
{
}
void MainWindow::enemyAttack()
{
    int skill=QRandomGenerator::global()->bounded(1,4);
    if(isPlayerZhang){//玩家是张楚岚，对手是冯宝宝
        if(skill==1){
            int damage=18;
            ui->textEdit_log->append("冯宝宝使用了菜刀斩");
                playerHp-=damage;
            if(playerHp<0){
                playerHp=0;
            }
            ui->textEdit_log->append("你受到了"+QString::number(damage)+"点伤害");
        }
        else if (skill == 2)
        {
            int heal = 20;
            ui->textEdit_log->append("冯宝宝使用了 回血！");
            enemyHp += heal;

            if (enemyHp > 100)
                enemyHp = 100;

            ui->textEdit_log->append("冯宝宝恢复了 " + QString::number(heal) + " 点生命！");
        }
        else
        {
            int damage = 38;
            ui->textEdit_log->append("冯宝宝使用了 认真一刀！");
            playerHp -= damage;

            if (playerHp < 0)
                playerHp = 0;

            ui->textEdit_log->append("你受到了 " + QString::number(damage) + " 点伤害！");
        }
    }
    else
    {
        // 玩家是冯宝宝，敌人就是张楚岚
        if (skill == 1)
        {
            int damage = 20;
            ui->textEdit_log->append("张楚岚使用了 掌心雷！");
            playerHp -= damage;

            if (playerHp < 0)
                playerHp = 0;

            ui->textEdit_log->append("你受到了 " + QString::number(damage) + " 点伤害！");
        }
        else if (skill == 2)
        {
            int damage = 30;
            ui->textEdit_log->append("张楚岚使用了 阳五雷！");
            playerHp -= damage;

            if (playerHp < 0)
                playerHp = 0;

            ui->textEdit_log->append("你受到了 " + QString::number(damage) + " 点伤害！");
        }
        else
        {
            int damage = QRandomGenerator::global()->bounded(15, 31);
            ui->textEdit_log->append("张楚岚使用了 迅雷！");
            playerHp -= damage;

            if (playerHp < 0)
                playerHp = 0;

            ui->textEdit_log->append("你受到了 " + QString::number(damage) + " 点伤害！");
        }
    }

    updateBattleUI();

}


void MainWindow::on_pushButton_skill1_clicked()
{
    int damage;

    if (isPlayerZhang)
    {
        damage = 20;
        ui->textEdit_log->append("张楚岚使用了 掌心雷！");
    }
    else
    {
        damage = 25;
        ui->textEdit_log->append("冯宝宝使用了 菜刀斩！");
    }

    enemyHp -= damage;

    if (enemyHp < 0)
        enemyHp = 0;

    ui->textEdit_log->append("敌人受到了 " + QString::number(damage) + " 点伤害！");
    updateBattleUI();
    if (checkGameOver())
        return;

    enemyAttack();

    checkGameOver();
}
bool MainWindow::checkGameOver()
{
    if (enemyHp <= 0)
    {
        ui->pushButton_skill1->setEnabled(false);
        ui->pushButton_skill2->setEnabled(false);
        ui->pushButton_skill3->setEnabled(false);

        QMessageBox::information(this, "游戏结束", "你赢了！");
        return true;
    }

    if (playerHp <= 0)
    {
        ui->pushButton_skill1->setEnabled(false);
        ui->pushButton_skill2->setEnabled(false);
        ui->pushButton_skill3->setEnabled(false);

        QMessageBox::information(this, "游戏结束", "你输了！");
        return true;
    }

    return false;
}

void MainWindow::on_pushButton_skill2_clicked()
{
    if(isPlayerZhang){
        //张楚岚：阳五雷
        int damage =30;
        ui->textEdit_log->append("张楚岚使用了阳五雷");
         enemyHp-=damage;
        if(enemyHp<0)enemyHp=0;
        ui->textEdit_log->append("敌人受到了"+QString::number(damage)+"点伤害");
    }// 冯宝宝：回血
    else{
        int heal =20;
        ui->textEdit_log->append("冯宝宝使用了回血！");
            playerHp+=heal;
         if(playerHp>100){
                playerHp=100;
             ui->textEdit_log->append("你恢复了"+QString::number(heal)+"点生命值");
        }

         updateBattleUI();

         if (checkGameOver())
             return;

         enemyAttack();

         checkGameOver();


    }
}


void MainWindow::on_pushButton_skill3_clicked()
{
    if (isPlayerZhang)
    {
        // 张楚岚：迅雷，15~30随机伤害
        int damage = QRandomGenerator::global()->bounded(15, 31);
        ui->textEdit_log->append("张楚岚使用了 迅雷！");
        enemyHp -= damage;

        if (enemyHp < 0)
            enemyHp = 0;

        ui->textEdit_log->append("敌人受到了 " + QString::number(damage) + " 点伤害！");
    }
    else
    {
        // 冯宝宝：认真一刀
        int damage = 38;
        ui->textEdit_log->append("冯宝宝使用了 认真一刀！");
        enemyHp -= damage;

        if (enemyHp < 0)
            enemyHp = 0;

        ui->textEdit_log->append("敌人受到了 " + QString::number(damage) + " 点伤害！");
    }

    updateBattleUI();

    if (checkGameOver())
        return;

    enemyAttack();

    checkGameOver();
}

void MainWindow::on_pushButton_back_clicked()
{
    ui->label->setText("一人之下 对战小游戏");
    // 显示主菜单按钮
    ui->pushButton->show();      // 开始游戏
    ui->pushButton_2->show();    // 退出游戏

    // 隐藏角色选择按钮
    ui->pushButton_3->hide();    // 张楚岚
    ui->pushButton_4->hide();    // 冯宝宝

    // 隐藏战斗界面
    ui->label_player->hide();
    ui->label_enemy->hide();
    ui->progressBar_player->hide();
    ui->progressBar_enemy->hide();
    ui->textEdit_log->hide();
    ui->pushButton_skill1->hide();
    ui->pushButton_skill2->hide();
    ui->pushButton_skill3->hide();
    ui->pushButton_back->hide();
    //清空战斗日志
    ui->textEdit_log->clear();
}

