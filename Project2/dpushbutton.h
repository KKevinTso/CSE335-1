#ifndef DPUSHBUTTON_H
#define DPUSHBUTTON_H

#include <QPushButton>


class DPushButton : public QPushButton
{
    Q_OBJECT
public:
    DPushButton(QWidget* qw):QPushButton(qw){}

signals:
    void iChanged(QObject*)const;

public slots:
    void pushed();
};

#endif // DPUSHBUTTON_H
