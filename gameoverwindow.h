#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H
#include <QDialog>
class gameoverwindow : public QDialog
{
    Q_OBJECT
public:
    gameoverwindow(int score , QWidget* parent = nullptr);
};

#endif // GAMEOVERWINDOW_H
