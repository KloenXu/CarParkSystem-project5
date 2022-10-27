#include "keyboardui.h"
#include "ui_keyboardui.h"

keyboardUI::keyboardUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keyboardUI)
{
    ui->setupUi(this);
}

keyboardUI::~keyboardUI()
{
    delete ui;
}
