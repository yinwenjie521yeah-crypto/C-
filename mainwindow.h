#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_skill1_clicked();

    void on_pushButton_skill2_clicked();

    void on_pushButton_skill3_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_help_clicked();

private:
    Ui::MainWindow *ui;
    int playerHp;
    int enemyHp;
    int playerMaxHp;
    int enemyMaxHp;
    bool isPlayerZhang;
    //增加可玩性，所以加入技能冷却
    int skill2Cooldown;
    int skill3Cooldown;
    void updateSkillButtons();
    void updateBattleUI();
    void enemyAttack();

    bool checkGameOver();
};
#endif // MAINWINDOW_H
