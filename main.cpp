#include <iostream>
#include "player.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    std::cout << "Starting AleePlayer...\n";
    QApplication a(argc, argv);
    Player musicPlayer;
    musicPlayer.show();
    return a.exec();
}
