#include "player.h"
#include "ui_player.h"
#include "about.h"
#include <QMediaPlayer>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>


Player::Player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);
}

Player::~Player()
{
    qInfo() << "Closing AleePlayer...\n";
    mPlayer->deleteLater();
    delete ui;
}

void Player::on_actionQuit_triggered()
{
    close();
}

void Player::on_playButton_pressed()
{
    if (mPlayer->state() == mPlayer->PlayingState) {
         qDebug() << "Pausing music...";
         mPlayer->pause();
     } else {
         qDebug() << "Playing music...";
         mPlayer->play();
     }
}

void Player::on_actionAbout_triggered()
{
    qDebug() << "Opening dialog";
    About about;
    about.exec();
}

void Player::on_mediaButton_pressed()
{
    QString mFile;
    QMessageBox msgbox;
    mFile = QFileDialog::getOpenFileName(this, "Open any audio file", QDir::homePath(), tr("Audio Files (*.mp3)"));
    if (mFile == NULL) {
        msgbox.setText("File is invalid.");
        return;
    } else {
        mPlayer->setMedia(QUrl::fromLocalFile(mFile));
        qDebug() << "Opening" << mFile;
        msgbox.setText("This audio file has been loaded.");
        msgbox.exec();
    }
}

void Player::on_actionOpen_triggered()
{
    QString mFile;
    QMessageBox msgbox;
    mFile = QFileDialog::getOpenFileName(this, "Open any audio file", QDir::homePath(), tr("Audio Files (*.mp3)"));
    if (mFile == NULL) {
        msgbox.setText("File is invalid.");
        return;
    } else {
        mPlayer->setMedia(QUrl::fromLocalFile(mFile));
        qDebug() << "Opening" << mFile;
        msgbox.setText("This audio file has been loaded.");
        msgbox.exec();
    }
}
