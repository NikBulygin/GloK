#include "../item_widget.h"

void item_widget::setlayout()
{
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(this->LineEdit_param->at(name));

//    for(int i = 0; i <= 1; i++)
//    {
//        for (int j = 0; j <= 2; j++)
//        {
//            layout->addWidget(this->PosSlider_XYZ->at(i)->at(j));
//        }
//    }
    layout->addWidget(this->Label_parent);
    QGridLayout* gridlayout = new QGridLayout();
    for(int i = 0; i <= 2; i++)
    {
            gridlayout->addWidget(
                        this->PosLabel_XYZ->at(0)->at(i),
                        i,
                        0
                        );

            gridlayout->addWidget(
                        this->PosSlider_XYZ->at(0)->at(i),
                        i,
                        1
                        );

            gridlayout->addWidget(
                        this->PosLabel_XYZ->at(1)->at(i),
                        i,
                        2
                        );

            gridlayout->addWidget(
                        this->PosSlider_XYZ->at(1)->at(i),
                        i,
                        3
                        );

    };
    layout->addLayout(gridlayout);



    QGridLayout* gridlayout1 = new QGridLayout();
    for (int i = 0; i <= 2; i++)
    {
        gridlayout1->addWidget(
                    this->RotLabel_XYZ->at(i),
                    i,
                    0
                    );
        gridlayout1->addWidget(
                    this->RotSlidex_XYZ->at(i),
                    i,
                    1
                    );
    }
    layout->addLayout(gridlayout1);

    for (int i = 0; i <= 3; i++)
    {
        layout->addWidget(this->LineEdit_param->at(i));
    }

    this->setLayout(layout);
}
