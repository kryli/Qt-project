#include "dialogabout.h"
#include "ui_dialogabout.h"

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
    QGridLayout* layout = ui->gridLayout;
    imageWidget* icon = new imageWidget;
    icon->setAttribute(Qt::WA_DeleteOnClose);
    layout->addWidget(icon, 0, 1);
    for (int i = 0; i < layout->columnCount(); i++)
        layout->setColumnStretch(i, 1);
}

DialogAbout::~DialogAbout()
{
    delete ui;
}
