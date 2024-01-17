#include "dialogitem.h"
#include "ui_dialogitem.h"

DialogItem::DialogItem(QWidget *parent, QList<QString> parentRow) :
    QDialog(parent),
    ui(new Ui::DialogItem)
{
    ui->setupUi(this);
    ui->lineEditName->setText(parentRow[1]);
    ui->lineEditCalories->setText(parentRow[2]);
    ui->lineEditFats->setText(parentRow[3]);
    ui->lineEditCarb->setText(parentRow[4]);
    ui->lineEditFiber->setText(parentRow[5]);
    ui->lineEditProtein->setText(parentRow[6]);    
}

DialogItem::~DialogItem()
{
    delete ui;
}

QList<QString> DialogItem::getUpdatedData()
{
    QList<QString> data;

    data << ui->lineEditName->text();
    data << ui->lineEditCalories->text();
    data << ui->lineEditFats->text();
    data << ui->lineEditCarb->text();
    data << ui->lineEditFiber->text();
    data << ui->lineEditProtein->text();

    return data;

}
