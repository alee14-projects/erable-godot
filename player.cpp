/*
    AleePlayer: Music player in Qt
    Copyright (C) 2020 Alee Productions

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "player.h"
#include "ui_player.h"
#include "about.h"
#include "library.h"

void Player::loadFile()
{
    QMessageBox msgbox;
    mFile = QFileDialog::getOpenFileName(this, tr("Open any audio file"), QDir::homePath(), tr("Audio Files (*.mp3 *.wav *.ogg *.flac *.mp4)"));
    if (mFile == NULL) {
        qDebug() << tr("File cannot be found");
        msgbox.setWindowTitle(tr("Uh oh! An error has occured!"));
        msgbox.setText(tr("File is invalid. Maybe try loading a valid audio file."));
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.exec();
        return;
    } else {
        mPlayer->setMedia(QUrl::fromLocalFile(mFile));
        qDebug() << tr("Opening") << mFile;
        msgbox.setWindowTitle(tr("Success!"));
        msgbox.setText(tr("This audio file has been loaded."));
        msgbox.setIcon(QMessageBox::Information);
        msgbox.exec();
        ui->volumeSlider->setValue(100);
        ui->playButton->setText(tr("Play"));
        return;
    }
}



Player::Player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);

    ui->library->setModel(new Library());

    connect(mPlayer, &QMediaPlayer::positionChanged, this, &Player::on_positionChanged);
    connect(mPlayer, &QMediaPlayer::durationChanged, this, &Player::on_durationChanged);

}

Player::~Player()
{
    qInfo() << tr("Closing AleePlayer...");
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
         qDebug() << tr("Pausing music...");
         mPlayer->pause();
         ui->playButton->setText(tr("Play"));
     } else {
         qDebug() << tr("Playing music...");
         mPlayer->play();
         ui->playButton->setText(tr("Pause"));
         amount++;
         //qDebug() << "You have pressed play for" << amount << "time(s).";
     }

}

void Player::on_stopButton_pressed()
{
    qInfo() << tr("Stopping music...");
    mPlayer->stop();
    ui->volumeSlider->setEnabled(false);
    ui->volumeSlider->setValue(100);
    ui->playbackSlider->setEnabled(false);
    ui->playbackSlider->setValue(0);
}

void Player::on_actionAbout_triggered()
{
    qDebug() << tr("Opening about dialog");
    About about;
    about.exec();
}

void Player::on_mediaButton_pressed()
{
    loadFile();
}

void Player::on_actionOpen_triggered()
{
    loadFile();
}


void Player::on_volumeSlider_sliderMoved(int position)
{
    mPlayer->setVolume(position);
}

void Player::on_playbackSlider_sliderMoved(int position)
{
    mPlayer->setPosition(position);
}

void Player::on_positionChanged(qint64 position)
{
    ui->playbackSlider->setValue(position);
}

void Player::on_durationChanged(qint64 position)
{
    ui->playbackSlider->setMaximum(position);
}
