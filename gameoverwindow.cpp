#include "gameoverwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

gameoverwindow::gameoverwindow(int score, QWidget* parent)
    : QDialog(parent)
{
    this->setWindowTitle("END GAME");
    this->resize(300, 200);

    QLabel* title_label = new QLabel("<h2>GAME OVER</h2>", this);
    title_label->setAlignment(Qt::AlignCenter);

    QLabel* score_label = new QLabel(
        "<p style='font-size:12px;'>Your score: <b>" + QString::number(score) + "</b></p>",
        this
        );
    score_label->setAlignment(Qt::AlignCenter);

    QPushButton* close_button = new QPushButton("OK", this);
    connect(close_button, &QPushButton::clicked, this, &gameoverwindow::accept);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(title_label);
    layout->addWidget(score_label);
    layout->addWidget(close_button);

    setLayout(layout);
}
