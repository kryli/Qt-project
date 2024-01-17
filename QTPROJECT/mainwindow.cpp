#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include "dialogcategories.h"
#include "dialogitem2.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), tableModel(new TableModel), listModel(new QStringListModel), proxyModel(new ProxyModel)
{
    ui->setupUi(this);

    proxyModel->setSourceModel((tableModel));
    ui->tableView->setModel(proxyModel);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(7, true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    QList<QString> categ = tableModel->getCategories();
    categ.sort();
    listModel->setStringList(categ);
    ui->listView->setModel(listModel);

    ui->tableView->setSortingEnabled(true);
    visibleElements(0);
    translator = new QTranslator(this);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, &QTableView::customContextMenuRequested, this, &MainWindow::on_tableView_customContextMenuRequested);
    createAction();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tableModel;
    delete listModel;
    delete proxyModel;

}

//void MainWindow::on_lineEditSearch_textChanged(const QString &arg1)
//{
//    ProxyModel* proxyModel = qobject_cast<ProxyModel*>(ui->tableView->model());
//    if (proxyModel)
//    {
//        QString searchString = ui->lineEditSearch->text();
//        proxyModel->setSearchText(searchString);
//    }
//}
void MainWindow::on_lineEditSearch_textChanged(const QString &arg1)
{
    ProxyModel* proxyModel = qobject_cast<ProxyModel*>(ui->tableView->model());
    if (proxyModel)
    {
        QString searchString = ui->lineEditSearch->text();
        proxyModel->setSearchText(searchString);
    }
}

void MainWindow::on_buttonItem_clicked()
{
    Dialog addDialog;
    if(addDialog.exec())
    {
        //add data here !
        QList<QString> fromForm = addDialog.addItem();
        qDebug() << addDialog.addItem();
        fromForm.insert(0, "1");
        fromForm.insert(7, ui->labelCategory->text());
        tableModel->appendRow(fromForm);
    }
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{

    QString selectedItemText = ui->listView->model()->data(index, Qt::DisplayRole).toString();
    proxyModel->setCategory(selectedItemText);
    ui->labelCategory->setText(selectedItemText);


    visibleElements(1);
}

void MainWindow::on_buttonCategory_clicked()
{
    DialogCategories addDialog;
    if(addDialog.exec())
    {
        QString fromForm = addDialog.addItem();
        qDebug() << addDialog.addItem();
        int row = listModel->rowCount();
        listModel->insertRows(row, 1);
        QModelIndex index = listModel->index(row);
        listModel->setData(index, fromForm);
    }
}

void MainWindow::visibleElements(int num)
{
    if (num == 1)
    {
        ui->labelCategory->setVisible(true);
        ui->tableView->setVisible(true);
        ui->buttonItem->setVisible(true);
        ui->labelSearch->setVisible(true);
        ui->lineEditSearch->setVisible(true);
    }
    else
    {
        ui->labelCategory->setVisible(false);
        ui->tableView->setVisible(false);
        ui->buttonItem->setVisible(false);
        ui->labelSearch->setVisible(false);
        ui->lineEditSearch->setVisible(false);
    }
}
void MainWindow::setEditInformation(const QList<QString>& data, const QModelIndex& index)
{

    tableModel->setData(proxyModel->mapToSource(index), data);


    QModelIndex proxyIndex = proxyModel->mapFromSource(index);
    QModelIndex displayIndex = tableModel->index(proxyIndex.row(), proxyIndex.column());
    ui->tableView->setCurrentIndex(displayIndex);
}
//void MainWindow::editRow(const QList<QString>& data, const QModelIndex& index)
//{
//    for(int column = 0; column < data.size(); column++)
//    {
//        tableModel->setData(index, data[column]);
//    }

//    // Emit the dataChanged() signal
//    tableModel->dataChanged(index, index, QVector<int>() << Qt::DisplayRole);
//}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QList<QString> row = tableModel->getRow(proxyModel->mapToSource(index).row());

    DialogItem2 dialogItem(nullptr, row);

    if (dialogItem.exec())
    {
        QList<QString> data = dialogItem.getUpdatedData();

//        editRow(data, index);
        setEditInformation(data, index);

        qDebug() << data;
    }
}
//void MainWindow::on_tableView_clicked(const QModelIndex &index)
//{
//    QList<QString> row = tableModel->getRow(proxyModel->mapToSource(index).row());

//    DialogItem2 dialogItem(nullptr, row);

////    DialogItem2 dialogItem(nullptr, row);
//    if (dialogItem.exec())
//    {
//        QList<QString> data = dialogItem.getUpdatedData();

//        qDebug() << data;
//        tableModel->setData(index, data);
//    }
//    // setChecked a method to do a galochka
//}

void MainWindow::translateEnglish()
{
    qApp->removeTranslator(translator);
    ui->retranslateUi(this);
}

void MainWindow::translateRussian()
{
    if (translator->load("ex_modelview_ru"))
        qApp->installTranslator(translator);
    ui->retranslateUi(this);
}

void MainWindow::createMenus()
{
    helpMenu = menuBar()->addMenu(tr("&help"));
    helpMenu->addAction(aboutAction);

    languageMenu = menuBar()->addMenu(tr("&Language"));
    languageMenu->addAction(languageEn);
    languageMenu->addAction(languageRu);


}

void MainWindow::createAction()
{
    aboutAction = new QAction(tr("&Info about"), this);

    connect(aboutAction, &QAction::triggered, this, &MainWindow::infoPage);

    languageEn = new QAction(tr("&English"), this);
    languageRu = new QAction(tr("&Russian"), this);

    connect(languageEn, &QAction::triggered, this, &MainWindow::translateEnglish);
    connect(languageRu, &QAction::triggered, this, &MainWindow::translateRussian);
}

void MainWindow::about()
{

}

void MainWindow::infoPage()
{
    DialogAbout about;
    if (about.exec())
    {

    }
}

void MainWindow::deleteRow()
{
    QModelIndex index = ui->tableView->currentIndex();
//    tableModel->removeRow(index.row());
    if (index.isValid())
    {
        ui->tableView->model()->removeRow(index.row());
    }
}



//void MainWindow::deleteRow()
//{
//    QModelIndex index = ui->tableView->currentIndex();
//    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

//    if (index.isValid())
//    {
//        model->removeRow(index.row());
//    } else {
//        qDebug() << "no";
//    }
//    ui->tableView->setModel(model);
//}


//void MainWindow::on_tableView_customContextMenuRequested(const QPoint &pos)
//{
//    QModelIndex index = ui->tableView->indexAt(pos);

//    if (index.isValid())
//    {
//        QMenu deleteMenu(this);

//        QAction* deleteAction = new QAction("Delete", this);

//        connect(deleteAction, &QAction::triggered, this, &MainWindow::deleteRow);

//        deleteMenu.addAction(deleteAction);

//        deleteMenu.exec(ui->tableView->viewport()->mapToGlobal(pos));
//    }
//}
//void MainWindow::deleteRow()
//{
//    QModelIndex index = ui->tableView->currentIndex();
//    if (index.isValid())
//    {
//        QModelIndex parent = index.parent();

//        if (tableModel->removeRow(index.row(), parent))
//        {
//            tableModel->layoutChanged();
//        }
//    }
//}

void MainWindow::on_tableView_customContextMenuRequested(const QPoint &pos)
{
    QModelIndex index = ui->tableView->indexAt(pos);

    if (index.isValid())
    {
        QMenu deleteMenu(this);
        QAction* deleteAction = deleteMenu.addAction("Delete");
        connect(deleteAction, &QAction::triggered, this, &MainWindow::deleteRow);

        deleteMenu.exec(ui->tableView->viewport()->mapToGlobal(pos));
    }
}



