/*
    Alee Audio Player: Audio player in Qt
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
#ifndef PLAYER_H
#define PLAYER_H
#include <QMediaPlayer>
#include <QStringListModel>
#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <taglib/fileref.h>

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

    int amount = 0;

private slots:

    void on_actionQuit_triggered();

    void on_playButton_pressed();

    void on_actionAbout_triggered();

    void on_mediaButton_pressed();

    void on_actionOpen_triggered();

    void on_stopButton_pressed();

    void loadFile();

    void on_volumeSlider_sliderMoved(int position);

    void on_playbackSlider_sliderMoved(int position);

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

private:
    Ui::Player *ui;
    QString mFile;
    QStringListModel *model;
};
#endif // PLAYER_H
