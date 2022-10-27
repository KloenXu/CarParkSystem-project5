#ifndef KEYBOARDPRESS_H
#define KEYBOARDPRESS_H

#include <QPushButton>

class keyboardPress : public QPushButton
{
    Q_OBJECT
public:
    explicit keyboardPress(QWidget *parent = nullptr);

private slots:
    void fun();

};

#endif // KEYBOARDPRESS_H
