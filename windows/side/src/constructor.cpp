#include "../side.h"



extern adapter_item* adp;
side::side(QWidget* parent) : QWidget(parent)
{
    this->wspc = new Widget_serial_port_connection();
    QVBoxLayout* topl = new QVBoxLayout();
    topl->addWidget(wspc);

    this->qlw = new QListWidget();
    QGridLayout* gridl = new QGridLayout(this);

    QVBoxLayout* secondlayout = new QVBoxLayout(this);
    QWidget* scrollcontentwidget = new QWidget(this);
    scrolllayout = new QVBoxLayout(scrollcontentwidget);



    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollcontentwidget);


    secondlayout->addWidget(scrollArea);
    gridl->addLayout(topl, 0,0);
    gridl->addLayout(secondlayout,1,0);
    this->setLayout(secondlayout);

    QObject::connect(adp, &adapter_item::updated, this, &side::update_scroll);
}


void side::update_scroll()
{
    for(int i = 0; scrolllayout->count(); i++)
    {
        delete scrolllayout->itemAt(i)->widget();
    }
    for (int i = 0; i < adp->get_count(); i++)
    {
        scrolllayout ->addWidget(new item_widget(adp->get_item(i)));
    }
}
