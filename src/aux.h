#include <QApplication>
#include <QWidget>
#include <QColor>

class GameLoop : public QWidget{
    Q_OBJECT

public:
    int playerOneY = 155;
    int playerTwoY = 155;

    void paintEvent(QPaintEvent *E);
    void keyPressEvent(QKeyEvent *E);
    GameLoop();

};
