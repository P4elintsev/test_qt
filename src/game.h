#pragma once

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QImage>
#include <QKeyEvent>

class Snake : public QWidget {

public:
    Snake(QWidget * = 0);

protected:
    void timerEvent(QTimerEvent*);
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *event);

private:
    QImage dot;
    QImage head;
    QImage apple;

    static const int DOT_WIDTH  = 10;
    static const int DOT_HEIGHT = 10;
    static const int FIELD_WIDTH   = 30;
    static const int FIELD_HEIGHT  = 30;
    static const int DELAY = 200;

    void loadImagen();
    void doDrawing();
    void locateApple();
    void move();
    void checkCollision();
    void gameOver();
    void check_apple();

    int timerId;

    QPoint fruit;

    enum Directions {
        left, right, up, down
    };

    Directions dir;

    bool startGame;
    QVector<QPoint> dots;

    void initGame();
};

