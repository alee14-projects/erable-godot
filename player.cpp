#include <iostream>
#include "player.h"
#include "ui_player.h"
#include "about.h"
#include <QMediaPlayer>


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

void Player::on_pushButton_pressed()
{
    std::cout << "Playing music...\n";
    mPlayer->setMedia(QUrl::fromLocalFile("/home/andrew/Music/4616-werq-by-kevin-macleod.mp3"));
    mPlayer->setVolume(50);
    mPlayer->play();
}

void Player::on_actionAbout_triggered()
{
    std::cout << "Opening dialog\n";
    About about;
    about.setModal(true);
    about.exec();
}
