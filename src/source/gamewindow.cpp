#include "gamewindow.h"
#include "gameoverwindow.h"
#include <QRandomGenerator>
#include <QString>
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
gamewindow::gamewindow(QWidget* parent ) : QWidget(parent)
{
    this->setWindowTitle("Click Game");
    timer = new QTimer(this);
    timer_label = new QLabel("Time : 30" , this);
    QHBoxLayout* timer_layout = new QHBoxLayout(this);
    timer_layout->addWidget(timer_label);
    timer_layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    button = new QPushButton("Click me" , this);
    button->resize(100 , 50);
    button->setCursor(Qt::OpenHandCursor);
    movebutton();
    connect(timer , &QTimer::timeout , this ,  [&](){
        timeLeft--;
        timer_label->setText("Time : " + QString::number(timeLeft));
        if( timeLeft <= 0)
            {
            timer->stop();
            button->setEnabled(false);
            this->close();

            gameoverwindow close_wnd(score , this);
            close_wnd.exec();

            emit gameover();

        }
    });
    connect(button, &QPushButton::clicked, this, &gamewindow::on_button_clicked);
    connect( this , &gamewindow::start_timer , this , &gamewindow::on_button_firsttime_clicked);
    connect( this , &gamewindow::buttonClicked , this , &gamewindow::addscore);
}

void gamewindow::on_button_clicked()
{
    emit buttonClicked();
    if( score == 1 )
    {
        emit start_timer();
    }
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

void gamewindow::on_button_firsttime_clicked()
{
    timer->start(1000);
}


void gamewindow::closeEvent(QCloseEvent *event)
{
    if( timer->isActive() )
    {
        timer->stop();
    }
    timer->disconnect();
    button->disconnect();
    emit window_closed();
    event->accept();
}
