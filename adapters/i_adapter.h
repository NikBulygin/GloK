#ifndef I_ADAPTER_H
#define I_ADAPTER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QHash>
#include <QString>
#include <QRegularExpression>

#include "../item/adapter_item.h"
#include "../item/item.h"
class i_adapter : public QObject
{
    Q_OBJECT
public:
    i_adapter();

    adapter_item* get_adapter_item() {
        return this->adt_itm;
    }
    virtual QVector<QString> get_name_points()
    {
        QVector<QString> result;
        return result;
    }

    int get_point_by_name(QString input)
    {
        return this->hash_table->value(input);
    }

    virtual void connect_to_point(int i, QString password = nullptr) {}

protected:    
    adapter_item* adt_itm;
    QHash<QString, int>* hash_table;

    void add_item_to_adapter(item* itm);

    void update_geometry(adapter_item::Sensor_Area index,
                        QVector<float> new_geometry);

    void update_rotate(adapter_item::Sensor_Area index,
            float x, float y, float z,
                       bool is_zero = false);

    void update_name(adapter_item::Sensor_Area index,
                     QString new_name);


signals:
    void config_was_accepted();

protected slots:
    void get_new_data(QJsonObject* jsonobj);
    void get_config_data(QJsonObject* jsonobj);

};

#endif // I_ADAPTER_H
