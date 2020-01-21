#include "player.h"
#include <QMessageBox>
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    qInfo() << "AleePlayer: A music player by Alee Productions. Licensed with GPL-3.0\n";
    QApplication a(argc, argv);
    Player musicPlayer;
    musicPlayer.show();
    return a.exec();
}
