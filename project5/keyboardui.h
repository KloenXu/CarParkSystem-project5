#ifndef KEYBOARDUI_H
#define KEYBOARDUI_H

#include <QWidget>

namespace Ui {
class keyboardUI;
}

class keyboardUI : public QWidget
{
    Q_OBJECT

public:
    explicit keyboardUI(QWidget *parent = nullptr);
    ~keyboardUI();

private:
    Ui::keyboardUI *ui;
};

#endif // KEYBOARDUI_H
