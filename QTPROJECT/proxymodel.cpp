#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent) : QSortFilterProxyModel(parent), category("bakery") {}
QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel()->headerData(section, orientation, role);
}
bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex categoryIndex = sourceModel()->index(source_row, 7, source_parent);
    if (sourceModel()->data(categoryIndex).toString() == category)
        return true;

    if ()

    if (m_searchText.isEmpty())
        return true;

    for (int i = 0; i < sourceModel()->columnCount(source_parent); ++i)
    {
        QModelIndex index = sourceModel()->index(source_row, i, source_parent);
        QString data = sourceModel()->data(index).toString();
        if (data.contains(m_searchText, Qt::CaseInsensitive))
            return true;
    }
    return false;
}

void ProxyModel::setCategory(const QString& category)
{
    this->category = category;
    invalidateFilter();
}

void ProxyModel::setSearchText(const QString& searchText)
{
    m_searchText = searchText;
    invalidateFilter();
}
