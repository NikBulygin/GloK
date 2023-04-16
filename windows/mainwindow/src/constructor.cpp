#include "../mainwindow.h"

MainWidget::MainWidget(QWidget* parent) : QMainWindow(parent)
{
    this->side_widtet = new side (this);
    this->widg3d = new widget3d(this);
    this->wgh = new Widget_Gesture_Handler(this);

    QWidget *centralWidget = new QWidget(this); // создаем центральный виджет
    setCentralWidget(centralWidget); // устанавливаем его как центральный виджет окна

    QHBoxLayout *layout = new QHBoxLayout(centralWidget); // создаем горизонтальный макет на центральном виджете
    layout->setContentsMargins(0, 0, 0, 0); // устанавливаем отступы по краям

    // создаем первый виджет
//    QWidget *widget1 = new QWidget(centralWidget);
    this->side_widtet->setMinimumWidth(width() * 0.3); // задаем минимальную ширину
    this->side_widtet->setMinimumHeight(height()); // задаем минимальную ширину
//    this->side_widtet->setStyleSheet("background-color: red;"); // устанавливаем красный фон
    layout->addWidget(this->side_widtet); // добавляем в макет

    // создаем второй виджет
//    QWidget *widget2 = new QWidget(centralWidget);
    this->widg3d->setMinimumWidth(width() * 0.5); // задаем минимальную ширину
    this->widg3d->setMinimumHeight(height()); // задаем минимальную ширину
//    widget2->setStyleSheet("background-color: blue;"); // устанавливаем синий фон
    layout->addWidget(this->widg3d); // добавляем в макет


    // создаем третий виджет
//    QWidget *widget2 = new QWidget(centralWidget);
    this->wgh->setMinimumWidth(width() * 0.2); // задаем минимальную ширину
    this->wgh->setMinimumHeight(height()); // задаем минимальную ширину
//    widget2->setStyleSheet("background-color: blue;"); // устанавливаем синий фон
    layout->addWidget(this->wgh); // добавляем в макет

    // устанавливаем пропорции виджетов
    layout->setStretchFactor(this->side_widtet, 2); // первый виджет занимает 20% ширины, поэтому задаем коэффициент 1
    layout->setStretchFactor(this->widg3d, 4); // второй виджет занимает оставшиеся 80%, поэтому задаем коэффициент 4
    layout->setStretchFactor(this->wgh, 4); // второй виджет занимает оставшиеся 80%, поэтому задаем коэффициент 4
}
