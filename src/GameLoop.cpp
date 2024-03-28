#include "aux.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QDateTime>

GameLoop::GameLoop(){

}

void GameLoop::paintEvent(QPaintEvent *E){
    QPainter playerOne(this);
    QPainter playerTwo(this);
    QPainter ball(this);

    ball.setBrush(Qt::white);

    playerOne.setPen(QPen(Qt::black, 1));
    playerOne.setBrush(Qt::white);

    playerTwo.setPen(QPen(Qt::black, 1));
    playerTwo.setBrush(Qt::white);

    // Create a QTimer object
    QTimer *timer = new QTimer(this);

    // Connect the timeout() signal of the QTimer to the updateGame() slot
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));

    // Start the timer to trigger updates approximately every 16 milliseconds (roughly 60 FPS)
    timer->start(500);

    ball.drawRect(ballX, ballY, ballSize, ballSize);
    playerOne.drawRect(10, playerOneY, 30, 100);
    playerTwo.drawRect(width() - 40, playerTwoY, 30, 100);
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
    else if (event->key() == Qt::Key_W) {
        playerTwoY -= 10; // Adjust the movement speed as needed
        if (playerTwoY < 0) playerTwoY = 0; // Limit movement within the widget
        update();
    }
    else if (event->key() == Qt::Key_S) {
        playerTwoY += 10; // Adjust the movement speed as needed
        int maxY = height() - 100; // The maximum Y position to ensure the rectangle stays within the widget
        if (playerTwoY > maxY) playerTwoY = maxY;
        update();
    }

}

void GameLoop::updateGame() {
    static qint64 lastUpdateTime = QDateTime::currentMSecsSinceEpoch();
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    qreal deltaTime = (currentTime - lastUpdateTime) / 1000.0; // Convert milliseconds to seconds
    lastUpdateTime = currentTime;

    // Move the ball horizontally
    ballX += ballSpeedX * deltaTime;

    // Check for collisions with the horizontal walls
    if (ballX <= 0 || ballX >= width() - ballSize) {
        ballSpeedX = -ballSpeedX; // Reverse the horizontal direction
    }

    // Move the ball vertically
    ballY += ballSpeedY * deltaTime;

    // Check for collisions with the vertical walls
    if (ballY <= 0 || ballY >= height() - ballSize) {
        ballSpeedY = -ballSpeedY; // Reverse the vertical direction
    }

    // Check for collisions with players
    if (ballX <= 40 && ballY >= playerOneY && ballY <= playerOneY + 100) {
        ballSpeedX = -ballSpeedX; // Reverse the horizontal direction
    }
    else if (ballX >= width() - 70 && ballY >= playerTwoY && ballY <= playerTwoY + 100) {
        ballSpeedX = -ballSpeedX; // Reverse the horizontal direction
    }

    update(); // Trigger a repaint
}

