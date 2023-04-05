#include "../side.h"


side::side(adapter_item* adp_item, QWidget* parent) : QWidget(parent)
{
    this->adp_item = adp_item;
    this->qlw = new QListWidget();
    QVBoxLayout* mainlayout = new QVBoxLayout(this);
    QWidget* scrollcontentwidget = new QWidget(this);
    QVBoxLayout* scrolllayout = new QVBoxLayout(scrollcontentwidget);

//    for (int i = 0; i < 50; ++i) {
//        QLabel *label = new QLabel(QString("Item %1").arg(i + 1));

//        scrolllayout->addWidget(label);
//    }

    for (int i = 0; i < this->adp_item->get_count(); i++)
    {
        scrolllayout ->addWidget(new item_widget(this->adp_item->get_item(i)));
    }

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollcontentwidget);

    mainlayout->addWidget(scrollArea);
    this->setLayout(mainlayout);

}
