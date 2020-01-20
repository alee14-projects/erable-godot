#include <iostream>
#include "player.h"
#include "ui_player.h"
#include "about.h"
#include <QMediaPlayer>
#include <QFileDialog>


Player::Player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);
}

Player::~Player()
{
    std::cout << "Closing AleePlayer...\n";
    mPlayer->deleteLater();
    delete ui;
}

void Player::on_actionQuit_triggered()
{
    close();
}

void Player::on_playButton_pressed()
{
    QPushButton mPlay;

    std::cout << "Playing music...\n";

    mPlayer->play();
}

void Player::on_actionAbout_triggered()
{
    std::cout << "Opening dialog\n";
    About about;
    about.setModal(true);
    about.exec();
}

void Player::on_pauseButton_pressed()
{
    mPlayer->pause();
}

void Player::on_pushButton_pressed()
{
    QString mFile;
    mFile = QFileDialog::getOpenFileName(this, "Open any audio file", QDir::homePath(), tr("Audio Files (*.mp3)"));
    mPlayer->setMedia(QUrl::fromLocalFile(mFile));
}
