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
#include "player.h"
#include <QMessageBox>
#include <QDebug>
#include <QTranslator>
#include <QFile>
#include <QDir>

#include <QApplication>

int main(int argc, char *argv[])
{
    qInfo() << "Alee Audio Player: A music player by Alee Productions. Licensed with GPL-3.0.\n";

    qDebug() << "Creating files...";

    //Change this to appdata or .local/share in linux
    //QDir directory(QDir::homePath() + "/.aleeaudioplayer");

    //File file(directory.absoluteFilePath("test.txt"));

    //file.open(QFile::WriteOnly);
    //file.close();

    QApplication a(argc, argv);
    a.setApplicationName("Alee Audio Player");
    a.setApplicationVersion("0.2.0");
    a.setOrganizationName("Alee Productions");

    QTranslator translator;
    translator.load(QLocale(), "/home/andrew/Documents/GitHub/Alee Audio Player/translations/");
    a.installTranslator(&translator);

    Player musicPlayer;
    musicPlayer.show();
    return a.exec();
}
