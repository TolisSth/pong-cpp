#include "aux.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    GameLoop gameloop;

    gameloop.show();

    return app.exec();

}
