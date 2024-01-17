#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



QList<QString> Dialog::addItem()
{
    QList<QString> dataRow;
    dataRow.append(ui->NameEdit->text());
    dataRow.append(ui->CatEdit->text());
    dataRow.append(ui->FatEdit->text());
    dataRow.append(ui->CarbEdit->text());
    dataRow.append(ui->FiberEdit->text());
    dataRow.append(ui->ProteinEdit->text());
//    dataRow.append(ui-->text());
    return dataRow;
}


