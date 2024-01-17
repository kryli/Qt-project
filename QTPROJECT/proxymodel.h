#ifndef PROXYMODEL_H
#define PROXYMODEL_H
#include <QSortFilterProxyModel>


class ProxyModel: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    ProxyModel(QObject* parent = 0);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    void setCategory(const QString& category);
private:
    QString category;

public:
    void setSearchText(const QString& searchText);
private:
    QString m_searchText;

};



#endif // PROXYMODEL_H
