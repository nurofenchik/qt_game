#include "mainwindow.h"
#include "gamewindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window, QBrush(QPixmap(":/images/background.png")));
    this->setPalette(pal);
    this->setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    wnd = std::make_unique<gamewindow>();
    wnd->show();
    connect( wnd.get() , &gamewindow::gameover , this , &MainWindow::show_window);
}

void MainWindow::show_window()
{
    this->show();
}
