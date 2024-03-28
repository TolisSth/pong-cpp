#include "aux.h"
#include <QPainter>
#include <QKeyEvent>

GameLoop::GameLoop(){

}

void GameLoop::paintEvent(QPaintEvent *E){
    QPainter playerOne(this);
    QPainter playerTwo(this);

    playerOne.setPen(QPen(Qt::black, 1));
    playerOne.setBrush(Qt::white);

    playerTwo.setPen(QPen(Qt::black, 1));
    playerTwo.setBrush(Qt::white);

    playerOne.drawRect(10, playerOneY, 30, 100);
    playerTwo.drawRect(width() - 40, 155, 30, 100);
}

void GameLoop::keyPressEvent(QKeyEvent *event) {
    // Move player one up
    if (event->key() == Qt::Key_Up) {
        playerOneY -= 10; // Adjust the movement speed as needed
        if (playerOneY < 0) playerOneY = 0; // Limit movement within the widget
        update(); // Trigger a repaint
    }
    // Move player one down
    else if (event->key() == Qt::Key_Down) {
        playerOneY += 10; // Adjust the movement speed as needed
        int maxY = height() - 100; // The maximum Y position to ensure the rectangle stays within the widget
        if (playerOneY > maxY) playerOneY = maxY;
        update(); // Trigger a repaint
    }
}
