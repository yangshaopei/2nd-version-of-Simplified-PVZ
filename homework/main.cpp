#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource(game_Resourcepath);
    MainScene w;
    w.show();
    return a.exec();
}
