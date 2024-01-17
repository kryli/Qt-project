#include "dialogitem2.h"
#include "ui_dialogitem2.h"

DialogItem2::DialogItem2(QWidget *parent, QList<QString> parentRow) :
    QDialog(parent),
    ui(new Ui::DialogItem2)
{
    ui->setupUi(this);
    ui->lineName->setText(parentRow[1]);
    ui->lineEditCalories->setText(parentRow[2]);
    ui->lineEditFats->setText(parentRow[3]);
    ui->lineEditCarb->setText(parentRow[4]);
    ui->lineEditFiber->setText(parentRow[5]);
    ui->lineEditProtein->setText(parentRow[6]);
}

DialogItem2::~DialogItem2()
{
    delete ui;
}

QList<QString> DialogItem2::getUpdatedData()
{
    QList<QString> data;

    data << ui->lineName->text();
    data << ui->lineEditCalories->text();
    data << ui->lineEditFats->text();
    data << ui->lineEditCarb->text();
    data << ui->lineEditFiber->text();
    data << ui->lineEditProtein->text();

    return data;
}
