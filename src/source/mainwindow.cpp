#include "mainwindow.h"
#include "gamewindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #2E3440;");
    this->setWindowTitle("Simple Game Launcher");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    wnd = std::make_unique<gamewindow>();
    wnd->resize( 500 , 500);
    wnd->show();
    connect( wnd.get() , &gamewindow::gameover , this , &MainWindow::show_window);
    connect( wnd.get(),  &gamewindow::window_closed, this , &MainWindow::show_window);
}

void MainWindow::show_window()
{
    this->show();
}
