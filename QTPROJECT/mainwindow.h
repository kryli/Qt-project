#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tableModel.h"
#include <QMainWindow>
#include <QStringListModel>
#include "proxymodel.h"
#include "dialogitem.h"
#include <QTranslator>
#include "dialogabout.h"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void visibleElements(int num);

//private slots:
//    void on_tableView_clicked(const QModelIndex &index);

private slots:
    void on_buttonItem_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_buttonCategory_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void translateEnglish();

    void translateRussian();

    void infoPage();

    void on_lineEditSearch_textChanged(const QString &arg1);

//    void editRow(const QList<QString>& data, const QModelIndex& index);

//    void showDeleteButton(const QPoint& del);

    void deleteRow();

    void on_tableView_customContextMenuRequested(const QPoint &pos);
    void setEditInformation(const QList<QString>& data, const QModelIndex& index);
private:
    void createMenus();

    void createAction();

    void about();

//    void editRow();


private:
    Ui::MainWindow *ui;
    TableModel *tableModel;
    QStringListModel* listModel;
    ProxyModel * proxyModel;
    QAction *aboutAction;
    QActionGroup *languageChose;
    QAction *menu;

    QTranslator *translator;
    QMenu *helpMenu;
    QMenu *languageMenu;
    QAction *languageEn;
    QAction *languageRu;


};
#endif
