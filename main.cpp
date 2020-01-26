#include "player.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QDir>

#include <QApplication>

int main(int argc, char *argv[])
{
    qInfo() << "AleePlayer: A music player by Alee Productions. Licensed with GPL-3.0.\n";

    qDebug() << "Creating files...";

    //QDir directory(QDir::homePath() + "/.alee-productions/AleePlayer");

   //File file(directory.absoluteFilePath("test.txt"));

    //file.open(QFile::WriteOnly);
    //file.close();

    QApplication a(argc, argv);
    Player musicPlayer;
    musicPlayer.show();
    return a.exec();
}
