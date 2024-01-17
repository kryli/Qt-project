#include "dialogcategories.h"
#include "ui_dialogcategories.h"

DialogCategories::DialogCategories(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCategories)
{
    ui->setupUi(this);
}

DialogCategories::~DialogCategories()
{
    delete ui;
}

QString DialogCategories::addItem()
{
    QString data;
    data.append(ui->lineEdit->text());

    return data;
}
