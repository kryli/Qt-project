#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QAbstractTableModel>


class TableModel: public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = nullptr);
    ~TableModel();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    QList<QString> getRow(int i) const;
    QList<QString> getCategories();
    void appendRow(const QList<QString> & data);
//    QPair<int, int> getSize();
    bool removeRow(int row, const QModelIndex &parent);


private:
    QList<QList<QString>> dataTable;
    QList<QString> header;
    QSet<QString> categories;

};

#endif // TABLEMODEL_H
