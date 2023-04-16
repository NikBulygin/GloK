#include "../item_widget.h"


item_widget::item_widget(item* related_obj, QWidget* parent) : QWidget(parent)
{
    this->blockSignals(true);
    this->obj = related_obj;


    QGridLayout *gridLayout = new QGridLayout(this);

    this->LineEdit_param = new QVector<QLineEdit*>();
    for(int i = width; i <= name; i++)
    {
        this->LineEdit_param->push_back(new QLineEdit(this));
        if(i == name)
            this->LineEdit_param->at(i)->setReadOnly(true);

        QObject::connect(this->LineEdit_param->at(i), &QLineEdit::editingFinished,
                         this, &item_widget::manual_updated);
    }

    gridLayout->addWidget(new QLabel("name"), 0, 0);
    gridLayout->addWidget(this->LineEdit_param->at(name), 0,1, 1, 2);
    gridLayout->addWidget(new QLabel("width"), 2, 0);
    gridLayout->addWidget(this->LineEdit_param->at(width), 2,1, 1, 2);
    gridLayout->addWidget(new QLabel("height"), 3, 0);
    gridLayout->addWidget(this->LineEdit_param->at(height), 3,1, 1, 2);
    gridLayout->addWidget(new QLabel("length"), 4, 0);
    gridLayout->addWidget(this->LineEdit_param->at(length), 4,1, 1, 2);
    gridLayout->addWidget(new QLabel("scale"), 5, 0);
    gridLayout->addWidget(this->LineEdit_param->at(scale), 5,1, 1, 2);

    this->LineEdit_PosXYZZ = new QVector<QLineEdit*>();
    for(int i = start; i <= end; i++)
    {
        for(int j = x; j <= z; j++)
        {
            this->LineEdit_PosXYZZ->push_back(new QLineEdit(this));

//            QObject::connect(this->LineEdit_PosXYZZ->at(i * z + j + i), &QLineEdit::editingFinished,
//                             this, &item_widget::manual_updated);
        }
    }

        gridLayout->addWidget(new QLabel("start"), 6, 0);

        gridLayout->addWidget(new QLabel("x"), 7, 0);
        gridLayout->addWidget(this->LineEdit_PosXYZZ->at(start * z + x), 7,1);
        gridLayout->addWidget(new QLabel("y"), 8, 0);
        gridLayout->addWidget(this->LineEdit_PosXYZZ->at(start * z + y), 8,1);
        gridLayout->addWidget(new QLabel("z"), 9, 0);
        gridLayout->addWidget(this->LineEdit_PosXYZZ->at(start * z + z), 9,1);

        gridLayout->addWidget(new QLabel("end"), 6, 2);
        gridLayout->addWidget(new QLabel("x"), 7, 2);
        gridLayout->addWidget(this->LineEdit_PosXYZZ->at(end * z + x + end), 7,3);
        gridLayout->addWidget(new QLabel("y"), 8, 2);
        gridLayout->addWidget(this->LineEdit_PosXYZZ->at(end * z + y + end), 8,3);
        gridLayout->addWidget(new QLabel("z"), 9, 2);
        gridLayout->addWidget(this->LineEdit_PosXYZZ->at(end * z + z + end), 9,3);


        this->RotSlidex_XYZ = new QVector<QSlider*>();
        this->RotZero_XYZ = new QVector<QLineEdit*>();
        for(int i = x; i <= z; i++)
        {
            this->RotSlidex_XYZ->push_back(new QSlider(Qt::Vertical ,this));
            this->RotZero_XYZ->push_back(new QLineEdit(this));
            this->RotSlidex_XYZ->at(i)->setMinimum(rot_min);
            this->RotSlidex_XYZ->at(i)->setMaximum(rot_max);
            this->RotSlidex_XYZ->at(i)->setValue(rot_max);
            this->RotSlidex_XYZ->at(i)->setMinimumHeight(50);


//            QObject::connect(this->RotZero_XYZ->at(i), &QLineEdit::editingFinished,
//                             this, &item_widget::manual_updated);
//            QObject::connect(this->RotSlidex_XYZ->at(i), &QSlider::valueChanged,
//                             this, &item_widget::manual_updated);
        }

        QVBoxLayout* vbox1 = new QVBoxLayout();
        vbox1->addWidget(new QLabel("x"));
        vbox1->addWidget(this->RotSlidex_XYZ->at(x));
        vbox1->addWidget(this->RotZero_XYZ->at(x));

        QVBoxLayout* vbox2 = new QVBoxLayout();
        vbox2->addWidget(new QLabel("y"));
        vbox2->addWidget(this->RotSlidex_XYZ->at(y));
        vbox2->addWidget(this->RotZero_XYZ->at(y));

        QVBoxLayout* vbox3 = new QVBoxLayout();
        vbox3->addWidget(new QLabel("z"));
        vbox3->addWidget(this->RotSlidex_XYZ->at(z));
        vbox3->addWidget(this->RotZero_XYZ->at(z));

        QHBoxLayout* hbox = new QHBoxLayout();
        hbox->addLayout(vbox1);
        hbox->addLayout(vbox2);
        hbox->addLayout(vbox3);

        gridLayout->addLayout(hbox, 10, 0, 1,4);



    this->setLayout(gridLayout);
    this->update_all();
    QObject::connect(this->obj, &item::was_updated, this, &item_widget::update_all);

    this->blockSignals(false);
}
