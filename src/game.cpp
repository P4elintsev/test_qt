#include "game.h"

#include <QImage>
#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QMessageBox>
#include <QRandomGenerator>


Snake::Snake(QWidget *)
{
    this->resize(DOT_WIDTH * FIELD_WIDTH, DOT_HEIGHT * FIELD_HEIGHT);
    setStyleSheet("background-color:white;");
    loadImagen();
    initGame();
}

void Snake::timerEvent(QTimerEvent * e)
{
    Q_UNUSED(e);

    if (startGame) {
        check_apple();
        move();
        checkCollision();
    }
    repaint();
}
void Snake::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    if (key == Qt::Key_Left  && dir != Directions::right) { dir = Directions::left;  }
    if (key == Qt::Key_Right && dir != Directions::left)  { dir = Directions::right; }
    if (key == Qt::Key_Up    && dir != Directions::down)  { dir = Directions::up;    }
    if (key == Qt::Key_Down  && dir != Directions::up)    { dir = Directions::down;  }
}

void Snake::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doDrawing();
}

void Snake::loadImagen()
{
    dot.load("G:/skilbox_uch/git_skil/Snake/data/dot.png");
    head.load("G:/skilbox_uch/git_skil/Snake/data/head.png");
    apple.load("../data/apple.png");
}

void Snake::doDrawing()
{
    QPainter qp(this);

    if (startGame)
    {

        qp.drawImage(fruit.x() * DOT_WIDTH, fruit.y() * DOT_HEIGHT, apple);

        for (int i = 0; i < dots.size(); ++i)
        {
            if(i == 0){qp.drawImage(dots[i].x() * DOT_WIDTH, dots[i].y() * DOT_HEIGHT, head);}
            else      {qp.drawImage(dots[i].x() * DOT_WIDTH, dots[i].y() * DOT_HEIGHT, dot);}
        }

    }
    else{gameOver();}
}

void Snake::locateApple()
{
    int r = QRandomGenerator::global()->bounded(DOT_WIDTH);
    fruit.rx() = (r % DOT_WIDTH);

    r = QRandomGenerator::global()->bounded(DOT_HEIGHT);
    fruit.ry() = (r % DOT_HEIGHT);
}

void Snake::move()
{
    for  (int i = dots.size()-1; i > 0; --i)
    {
        dots[i] = dots[i-1];
    }

    switch (dir)
    {
        case left:  { dots[0].rx() -= 1; break; }
        case right: { dots[0].rx() += 1; break; }
        case up:    { dots[0].ry() -= 1; break; }
        case down:  { dots[0].ry() += 1; break; }
    }
}

void Snake::checkCollision()
{
    if (dots.size() > 4)
    {
        for (int i = 1; i < dots.size(); ++i)
        {
            if (dots[0] == dots[i]){startGame = false;}
        }
    }

    if(dots[0].x() >= FIELD_WIDTH)  { startGame = false; }
    if(dots[0].x() < 0)             { startGame = false; }
    if(dots[0].y() >= FIELD_HEIGHT) { startGame = false; }
    if(dots[0].y() < 0)             { startGame = false; }

    if(!startGame) {
        killTimer(timerId);
    }
}

void Snake::gameOver()
{
    QMessageBox Finished;
    Finished.setWindowTitle("Конец");
    QString style = "QMessageBox {background-color: white; font-size: 14pt;}";
    Finished.setStyleSheet(style);
    Finished.setText("Game Over");
    Finished.exec();

    initGame();
}

void Snake::check_apple()
{
    if (fruit == dots[0])
    {
        dots.push_back(QPoint(0,0));
        locateApple();
    }
}

void Snake::initGame()
{
    startGame = true;
    dir = right;

    dots.resize(3);

    for(int i = 0; i < dots.size(); ++i)
    {
        dots[i].rx() = dots.size() - i - 1;
        dots[i].ry() = 0;
    }

    locateApple();

    timerId = startTimer(DELAY);
}
