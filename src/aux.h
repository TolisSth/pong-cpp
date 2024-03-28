#include <QApplication>
#include <QWidget>
#include <QColor>

class GameLoop : public QWidget{
    Q_OBJECT

public:
    int ballSpeedX = 50;
    int ballSpeedY = 50;
    int ballX = 155;
    int ballY = 155;
    int ballSize = 15;
    int playerOneY = 155;
    int playerTwoY = 155;

    void paintEvent(QPaintEvent *E);
    void keyPressEvent(QKeyEvent *E);
    GameLoop();

private slots:
    void updateGame();


};
