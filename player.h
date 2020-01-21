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

    void on_playButton_pressed();

    void on_actionAbout_triggered();

    void on_mediaButton_pressed();

    void on_actionOpen_triggered();

    void on_stopButton_pressed();

    void mFileDialog();

private:
    Ui::Player *ui;
};
#endif // PLAYER_H
