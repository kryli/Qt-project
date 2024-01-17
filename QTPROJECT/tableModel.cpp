#include "tablemodel.h"
#include <QFile>
#include <QSize>

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QFile inputFile(":/rec/starbucks.csv");
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);
    header = inputStream.readLine().replace("\"", "").split(',');


    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        line = line.replace("\"", "");

        QList<QString> dataRow;
        for (QString& item : line.split(","))
            dataRow.append(item);

        categories.insert(dataRow.at(7));
        dataTable.append(dataRow);
    }
    inputFile.close();



}

TableModel::~TableModel()
{
    QFile outputFile("/Users/leo/Desktop/QTPROJECT/NewStarbucks.csv");
    outputFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream outputStream(&outputFile);
    for (int i = 0; i < header.size(); i++)
        outputStream << header[i] << (i < header.size()-1? ',' : '\n');

    for (int i = 0; i < dataTable.size(); i++)
    {
        for (int j = 0; j < dataTable[i].size(); j++)
            outputStream << dataTable[i][j] << (j < dataTable[i].size()-1? ',' : '\n');
    }
    outputFile.close();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return dataTable.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return header.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if(index.column() > 1 && index.column() < 7)
            return dataTable[index.row()][index.column()].toInt();
        return QVariant(dataTable[index.row()][index.column()]);
    }
    if (role == Qt::BackgroundRole)
    {
        return QColor(Qt::green);
    }

    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value)
    {
        dataTable[index.row()][index.column()] = value.toString();
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
            return header[section];
        else if (orientation == Qt::Vertical)
            return dataTable[section][0];
    }

    return QVariant();
}

bool TableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role))
    {
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

QList<QString> TableModel::getRow(int i) const
{
    return dataTable.at(i);
}


QList<QString> TableModel::getCategories()
{

    return QList<QString> (categories.begin(),categories.end());
}

void TableModel::appendRow(const QList<QString>& data)
{
    beginInsertRows(QModelIndex(), dataTable.size(), dataTable.size());
    dataTable.append(data);
    endInsertRows();
}

bool TableModel::removeRow(int row, const QModelIndex &parent)
{
    if (row >= 0 && row < dataTable.size())
    {
        beginRemoveRows(parent, row, row);
        dataTable.removeAt(row);
        endRemoveRows();
        return true;
    }
    return false;
}
