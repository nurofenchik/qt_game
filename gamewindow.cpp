#include "gamewindow.h"
#include <QRandomGenerator>
#include <QString>
gamewindow::gamewindow(QWidget* parent ) : QWidget(parent)
{
    this->setWindowTitle("Click Game");
    timer = new QTimer(this);
    timer_label = new QLabel("Time : 30" , this);
    timer_label->move(250,10);
    timer->start(1000);
    score_label = new QLabel("Score: 0", this);
    score_label->move(10, 10);
    score_label->resize(100,10);
    score_label->show();
    button = new QPushButton("Click me" , this);
    button->resize(100 , 50);
    movebutton();
    connect(timer , &QTimer::timeout , [=](){
        timeLeft--;
        timer_label->setText("Time : " + QString::number(timeLeft));
        if( timeLeft <= 0)
            {
            timer->stop();
            button->setEnabled(false);
        }
    });
    connect(button, &QPushButton::clicked, this, &gamewindow::on_button_clicked);
    connect(this , &gamewindow::buttonClicked , this , &gamewindow::addscore);
    connect(button , &QPushButton::clicked , this , &gamewindow::show_score);
}

void gamewindow::on_button_clicked()
{
    emit buttonClicked();
    movebutton();
}

void gamewindow::movebutton()
{
    int x = QRandomGenerator::global()->bounded(width() - button->width());
    int y = QRandomGenerator::global()->bounded(height() - button->height());
    button->move(x, y);
}

void gamewindow::addscore()
{
    score++;
}
void gamewindow::show_score()
{
    score_label->setText("Score : "+ QString::number(score));
}
