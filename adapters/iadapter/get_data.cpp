#include "../i_adapter.h"



void i_adapter::get_new_data(QJsonObject* jsonobj)
{
    if (jsonobj->contains("data"))
    {
        QJsonArray datasArray = jsonobj->value("data").toArray();

        foreach (const QJsonValue& data, datasArray) {
            if(data.isObject())
            {
                QJsonObject dataobj = data.toObject();
                float new_x = 0,
                        new_y = 0,
                        new_z = 0;
                QString name;

                if(dataobj.contains("name"))
                {
                    name = dataobj.value("name").toString();

                    if(dataobj.contains("rotate"))
                    {
                        QJsonArray rotateArray = dataobj.value("rotate").toArray();
                        if (rotateArray.size() == 3)
                        {
                            new_x = rotateArray[0].toDouble();
                            new_y = rotateArray[1].toDouble();
                            new_z = rotateArray[2].toDouble();
                        }
                    }

                    this->update_rotate(
                                static_cast<adapter_item::Sensor_Area>(this->hash_table->value(name)),
                                new_x,
                                new_y,
                                new_z
                                );
                }
            }


        }
    }
}

void i_adapter::get_config_data(QJsonObject* jsonobj)
{
    if (jsonobj->contains("config")) {
        QJsonArray configArray = jsonobj->value("config").toArray();

        foreach (const QJsonValue& configValue, configArray) {
            QString new_name;
            float width = 0,
                    height = 0,
                    length = 0,
                    scale = 0,
                    rotate_x = 0,
                    rotate_y = 0,
                    rotate_z = 0;

//            QVector<float>* new_m_geometry = new QVector<float>;
//            QVector<float>* new_m_rotate = new QVector<float>;
            QVector3D* new_start_pos = new QVector3D(0,0,0);
            int parent = -1;

            if (configValue.isObject()) {
                QJsonObject configObj = configValue.toObject();
                if (configObj.contains("name")) {
                    new_name = configObj.value("name").toString();
                }
                else {
                    new_name = "undefine";
                }

                if (configObj.contains("geometry") || configObj.value("geometry").isNull()) {
                    QJsonObject geometryObj = configObj["geometry"].toObject();


                    width = geometryObj.value("width").toDouble();
                    height = geometryObj.value("height").toDouble();
                    length = geometryObj.value("length").toDouble();
                    scale = geometryObj.value("scale").toDouble();
                }
                else {

                    width = 0.5;
                    height = 0.25;
                    length = 2;
                    scale = 0.5;
                }

                if (configObj.contains("rotate") || configObj.value("rotate").isNull()) {
                    QJsonObject rotateObj = configObj["rotate"].toObject();

                    rotate_x = rotateObj.value("x").toDouble();
                    rotate_y = rotateObj.value("y").toDouble();
                    rotate_z = rotateObj.value("z").toDouble();
                }
                else {
                    rotate_x = 0;
                    rotate_y = 0;
                    rotate_z = 0;
                }

                if (configObj.contains("start_pos") || configObj.value("start_pos").isNull()) {
                    QJsonObject start_pos = configObj["start_pos"].toObject();
                    new_start_pos->setX(start_pos.value("x").toDouble());
                    new_start_pos->setY(start_pos.value("y").toDouble());
                    new_start_pos->setZ(start_pos.value("z").toDouble());
                }
                else {
                    new_start_pos->setX(0);
                    new_start_pos->setY(0);
                    new_start_pos->setZ(0);
                }

                if(configObj.contains("parent") || configObj.value("parent").isNull()) {
                    QString str_parent = configObj.value("parent").toString();
                    bool is_number;
                    parent = str_parent.toInt(&is_number);
                    if(!is_number)
                        parent = this->get_point_by_name(str_parent);

//                    parent = parent == 0 ? -1 : parent; //null defined as 0
                    this->adt_itm->get_items()->push_back(
                                new item(new_start_pos,
                                         new_name,
                                         width,
                                         height,
                                         length,
                                         scale,
                                         rotate_x,
                                         rotate_y,
                                         rotate_z,
                                         this->adt_itm->get_item(parent)));
                }
                else {
                    this->adt_itm->get_items()->push_back(
                                new item(new_start_pos,
                                         new_name,
                                         width,
                                         height,
                                         length,
                                         scale,
                                         rotate_x,
                                         rotate_y,
                                         rotate_z,
                                         nullptr));
                }

                this->hash_table->insert(new_name, this->adt_itm->get_count() - 1);


            }
        };
    }
    emit config_was_accepted();
}
