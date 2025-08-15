#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
class gamewindow : public QWidget
{
    Q_OBJECT

private:
    QPushButton* button;
    QTimer* timer;
    QLabel* timer_label;
    int timeLeft = 30;
    QLabel* score_label;
    int score = 0;

signals:
    void buttonClicked();
    void start_timer();
    void gameover();
private slots:
    void on_button_clicked();
    void on_button_firsttime_clicked();
    void movebutton();
    void addscore();
    void show_score();
public:
    explicit gamewindow(QWidget* parent = nullptr);
};

#endif // GAMEWINDOW_H
