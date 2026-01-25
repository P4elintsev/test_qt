#include <QApplication>
#include <game.h>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Snake game;
    game.setWindowTitle("Snake game test");
    game.show();

    return app.exec();
}
