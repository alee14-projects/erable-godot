#ifndef PLAYER_H
#define PLAYER_H
#include <QMediaPlayer>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Player; }
QT_END_NAMESPACE

class Player : public QMainWindow
{
    Q_OBJECT

public:
    Player(QWidget *parent = nullptr);
    ~Player();
    QMediaPlayer* mPlayer = new QMediaPlayer();

private slots:
    void on_actionQuit_triggered();

    void on_pushButton_pressed();

    void on_actionAbout_triggered();

private:
    Ui::Player *ui;
};
#endif // PLAYER_H
