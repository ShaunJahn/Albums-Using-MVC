#include "musicmodel.h"
#include <QString>

MusicModel::MusicModel(QObject *parent): QAbstractTableModel(parent)
{
}

MusicModel::~MusicModel()
{
    qDeleteAll(cdList);
}

int MusicModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return cdList.size();
}

int MusicModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 4;
}

QVariant MusicModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }

    if (role == Qt::DisplayRole)
    {
        int col = index.column();
        int row = index.row();
        if (col==0) return cdList.at(row)->getComposer();
        if (col==1) return cdList.at(row)->getTitle();
        if (col==2) return QString("%1").arg(cdList.at(row)->getCost(), 0, 'f', 2);
        else return cdList.at(row)->getRating();
    }

    return QVariant();
}

QVariant MusicModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section)
    {
    case 0: return QString("Composer/artist");  break;
    case 1: return QString("Album title");      break;
    case 2: return QString("Replacement cost"); break;
    case 3: return QString("Rating");           break;
    default: return QVariant();
    }

    return QVariant();
}

bool MusicModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role==Qt::EditRole)
    {
        int col = index.column();
        int row = index.row();
        switch (col)
        {
        case 0: cdList.at(row)->setComposer(value.toString());   break;
        case 1: cdList.at(row)->setTitle(value.toString());      break;
        case 2: cdList.at(row)->setCost(value.toFloat());        break;
        case 3: cdList.at(row)->setRating(value.toInt());        break;
        default: return false;
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags MusicModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    else
        return 0;
}

void MusicModel::addCD(CD *cd)
{
    int row = cdList.size();
    beginInsertRows(QModelIndex(), row+1, row+1);
    cdList.append(cd);
    endInsertRows();
}

