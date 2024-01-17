#ifndef DIALOGITEM_H
#define DIALOGITEM_H

#include <QDialog>

namespace Ui {
class DialogItem;
}

class DialogItem : public QDialog
{
    Q_OBJECT

public:
    explicit DialogItem(QWidget *parent = nullptr, QList<QString> parentRow = {});
    ~DialogItem();


    QList<QString> getUpdatedData();



private:
    Ui::DialogItem *ui;
};

#endif // DIALOGITEM_H
