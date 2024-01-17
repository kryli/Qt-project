#ifndef DIALOGCATEGORIES_H
#define DIALOGCATEGORIES_H

#include <QDialog>

namespace Ui {
class DialogCategories;
}

class DialogCategories : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCategories(QWidget *parent = nullptr);
    ~DialogCategories();
    QString addItem();

private:
    Ui::DialogCategories *ui;
};

#endif // DIALOGCATEGORIES_H
