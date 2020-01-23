#include <QMediaPlayer>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include "player.h"
#include "ui_player.h"
#include "about.h"



void Player::mFileDialog()
{
    QString mFile;
    QMessageBox msgbox;
    mFile = QFileDialog::getOpenFileName(this, "Open any audio file", QDir::homePath(), tr("Audio Files (*.mp3 *.wav *.ogg)"));
    if (mFile == NULL) {
        qDebug() << "File cannot be found";
        msgbox.setWindowTitle("Uh oh! An error has occured!");
        msgbox.setText("File is invalid. Maybe try loading a valid audio file.");
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.exec();
        return;
    } else {
        mPlayer->setMedia(QUrl::fromLocalFile(mFile));
        qDebug() << "Opening" << mFile;
        msgbox.setWindowTitle("Success!");
        msgbox.setText("This audio file has been loaded.");
        msgbox.setIcon(QMessageBox::Information);
        msgbox.exec();
        ui->volumeSlider->setValue(100);
        return;
    }
}



Player::Player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);

}

Player::~Player()
{
    qInfo() << "Closing AleePlayer...";
    mPlayer->deleteLater();
    delete ui;
}

void Player::on_actionQuit_triggered()
{
    close();
}

void Player::on_playButton_pressed()
{
    ui->playbackSlider->setEnabled(true);
    ui->volumeSlider->setEnabled(true);
    if (mPlayer->state() == mPlayer->PlayingState) {
         qDebug() << "Pausing music...";
         mPlayer->pause();
         ui->playButton->setText("Pause");
     } else {
         qDebug() << "Playing music...";
         mPlayer->play();
         ui->playButton->setText("Play");
     }
}

void Player::on_stopButton_pressed()
{
    qInfo() << "Stopping music...";
    mPlayer->stop();
    ui->volumeSlider->setEnabled(false);
    ui->volumeSlider->setValue(100);
    ui->playbackSlider->setEnabled(false);
    ui->playbackSlider->setValue(0);
}

void Player::on_actionAbout_triggered()
{
    qDebug() << "Opening dialog";
    About about;
    about.exec();
}

void Player::on_mediaButton_pressed()
{
    mFileDialog();
}

void Player::on_actionOpen_triggered()
{
    mFileDialog();
}


void Player::on_volumeSlider_sliderMoved(int position)
{
    mPlayer->setVolume(position);
}
