#include <iostream>
#include "player.h"
#include "ui_player.h"

Player::Player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);
}

Player::~Player()
{
    delete ui;
}

void Player::on_actionQuit_triggered()
{
    std::cout << "Closing AleePlayer...\n";
    close();
}
