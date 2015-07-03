//------------------------------------------------------------------------------
//  This file is auto-generated. Please do not make any changes.
//------------------------------------------------------------------------------
#include "flydatalistmodel.h"
#include <QCoreApplication>
#include <QMutexLocker>
#include <QDebug>

FlyDataListModel::FlyDataListModel(const HashedList<FlyData>::FuncPtrHash hash, QObject *parent) :
    QAbstractListModel(parent),
    mMutex(),
    mData(hash)
{
    connect(this, SIGNAL(added(QList<FlyData>)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(removed(QList<FlyData>)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(added(QList<FlyData>)), this, SIGNAL(updated(QList<FlyData>)));
    connect(this, SIGNAL(changed(QList<FlyData>)), this, SIGNAL(updated(QList<FlyData>)));
}

QHash<int, QByteArray> FlyDataListModel::roleNames() const
{
    QHash<int, QByteArray> result;
    result[FlyDataAliveRole] = "fly_data_alive_role";
    result[FlyDataAngleRole] = "fly_data_angle_role";
    result[FlyDataBirthdayRole] = "fly_data_birthday_role";
    result[FlyDataColorRole] = "fly_data_color_role";
    result[FlyDataDescriptionRole] = "fly_data_description_role";
    result[FlyDataDestinationRole] = "fly_data_destination_role";
    result[FlyDataDistanceRole] = "fly_data_distance_role";
    result[FlyDataDouchenessRole] = "fly_data_doucheness_role";
    result[FlyDataIdRole] = "fly_data_id_role";
    result[FlyDataLifetimeRole] = "fly_data_lifetime_role";
    result[FlyDataPositionRole] = "fly_data_position_role";
    return result;
}

int FlyDataListModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
    {
        return this->mData.count();
    }
    return 0;
}

QVariant FlyDataListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() &&
            index.row() >= 0 &&
            index.row() < this->mData.count())
    {
        const FlyData& item(this->mData.at(index.row()));
        switch(role)
        {
        case FlyDataRole:
        {
            return QVariant::fromValue(item);
        }
        case FlyDataAliveRole:
        {
            return QVariant::fromValue(item.alive());
        }
        case FlyDataAngleRole:
        {
            return QVariant::fromValue(item.angle());
        }
        case FlyDataBirthdayRole:
        {
            return QVariant::fromValue(item.birthday());
        }
        case FlyDataDestinationRole:
        {
            return QVariant::fromValue(item.destination());
        }
        case FlyDataDistanceRole:
        {
            return QVariant::fromValue(item.distance());
        }
        case FlyDataDouchenessRole:
        {
            return QVariant::fromValue(item.doucheness());
        }
        case FlyDataIdRole:
        {
            return QVariant::fromValue(item.id());
        }
        case FlyDataLifetimeRole:
        {
            return QVariant::fromValue(item.lifetime());
        }
        case FlyDataPositionRole:
        {
            return QVariant::fromValue(item.position());
        }
        default:
            break;
        }
    }
    return QVariant();
}

void FlyDataListModel::remove(const FlyData& data)
{
    QMutexLocker locker(&this->mMutex);
    Q_UNUSED(locker)

    QString key;
    const int index = this->mData.indexOf(data, &key);
    if (index >= 0) {
        QList<FlyData> result;
        this->beginRemoveRows(QModelIndex(), index, index);
        result.append(this->mData.takeAt(index));
        this->endRemoveRows();
        emit this->removed(result);
    }
}

void FlyDataListModel::update(const FlyData& data)
{
    QMutexLocker locker(&this->mMutex);
    Q_UNUSED(locker)

    QString key;
    const int index = this->mData.indexOf(data, &key);
    if (index >= 0)
    {
        FlyData value = this->mData.at(index);
        if (value.merge(data))
        {
            this->mData.replace(index, value);
            const QModelIndex modelIndex = this->index(index);
            emit this->dataChanged(modelIndex, modelIndex);
            emit this->changed(QList<FlyData>() << value);
        }
    }
    else
    {
        const int count = this->mData.count();
        this->beginInsertRows(QModelIndex(), count, count);
        this->mData.append(data);
        this->endInsertRows();
        emit this->added(QList<FlyData>() << data);
    }
}

void FlyDataListModel::update(const QList<FlyData>& curr, bool remove)
{
    QMutexLocker locker(&this->mMutex);
    Q_UNUSED(locker)

    const QHash<QString, int>& prevIndices = this->mData.indices();
    const QMultiHash<int, QString>& prevKeysByIndices = this->mData.keys();
    const QSet<QString> prevKeys = prevIndices.keys().toSet();

    QHash<QString, int> currIndicesByKeys;
    QMultiHash<int, QString> currKeysByIndices;
    this->mData.generateIndices(curr, currIndicesByKeys, currKeysByIndices);
    const QSet<QString> currKeys = currIndicesByKeys.keys().toSet();

    const QSet<QString> changedKeys = prevKeys & currKeys;
    QSet<QString> removedKeys = remove ? prevKeys - currKeys : QSet<QString>();
    QSet<QString> appendedKeys = currKeys - prevKeys;

    if (!changedKeys.isEmpty())
    {
        QHash<int, FlyData> changedValues;
        foreach (const QString& key, changedKeys) {
            const int prevIndex = prevIndices.value(key);
            if (remove)
            {
                //less keys
                const QList<QString> keysChanged = prevKeysByIndices.values(prevIndex);
                foreach (const QString& keyChanged, keysChanged) {
                    removedKeys.remove(keyChanged);
                }
            }
            const int currIndex = currIndicesByKeys.value(key);
            {
                //more keys
                const QList<QString> keysChanged = currKeysByIndices.values(currIndex);
                foreach (const QString& keyChanged, keysChanged) {
                    appendedKeys.remove(keyChanged);
                }
            }
            FlyData value = this->mData.at(prevIndex);
            if (value.merge(curr.at(currIndex))) {
                changedValues.insert(prevIndex, value);
            }
        }
        const IntervalList intervals = Intervals::intervals(changedValues.keys());
        foreach (const Interval& interval, intervals) {
            for (int i = interval.first; i <= interval.second; ++i) {
                this->mData.replace(i, changedValues.value(i));
            }
            const QModelIndex changedIndexFrom = this->index(interval.first);
            const QModelIndex changedIndexTo = this->index(interval.second);
            emit this->dataChanged(changedIndexFrom, changedIndexTo);
        }
        emit this->changed(changedValues.values());
    }
    if (!removedKeys.isEmpty()) {
        QList<int> removedIndices;
        foreach (const QString& key, removedKeys) {
            removedIndices.append(prevIndices.value(key));
        }
        const IntervalList intervals = Intervals::intervals(removedIndices);
        const int intervalsCount = intervals.count();
        QList<FlyData> result;
        for (int i = intervalsCount - 1; i >= 0; --i) {
            const Interval& interval = intervals.at(i);
            this->beginRemoveRows(QModelIndex(), interval.first, interval.second);
            for (int j = interval.second; j >= interval.first; --j) {
                result.append(this->mData.takeAt(j));
            }
            this->endRemoveRows();
        }
        emit this->removed(result);
    }
    if (!appendedKeys.isEmpty())
    {
        QSet<int> indicesSet;
        foreach (const QString& key, appendedKeys) {
            indicesSet.insert(currIndicesByKeys.value(key));
        }
        QList<int> indices = indicesSet.toList();
        qSort(indices);
        const int first = this->mData.count();
        const int second = first + indices.count() - 1;
        QList<FlyData> result;
        this->beginInsertRows(QModelIndex(), first, second);
        foreach (int index, indices) {
            const FlyData& value = curr.at(index);
            result.append(value);
            this->mData.append(value);
        }
        this->endInsertRows();
        emit this->added(result);
    }
}
