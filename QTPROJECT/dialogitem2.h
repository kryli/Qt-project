#ifndef DIALOGITEM2_H
#define DIALOGITEM2_H

#include <QDialog>

namespace Ui {
class DialogItem2;
}

class DialogItem2 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogItem2(QWidget *parent = nullptr, QList<QString> parentRow = {});
    ~DialogItem2();


    QList<QString> getUpdatedData();



private:
    Ui::DialogItem2 *ui;
};

#endif // DIALOGITEM2_H
