#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include <QObject>


extern adapter_item* adp;
class KeyboardController : public QObject
{
    Q_OBJECT
public:
    KeyboardController();

private:
    bool read_data = false;
public slots:
    void toggle_read_data;
signals:
    void was_updated();
};

#endif // KEYBOARDCONTROLLER_H
