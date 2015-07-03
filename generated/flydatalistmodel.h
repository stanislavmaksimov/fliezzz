//------------------------------------------------------------------------------
//  This file is auto-generated. Please do not make any changes.
//------------------------------------------------------------------------------
#ifndef FLYDATALISTMODEL_H
#define FLYDATALISTMODEL_H

#include <QAbstractListModel>
#include <QMutex>
#include "merger.h"
#include "flydata.h"

enum FlyDataRoles
{
    FlyDataRole = Qt::UserRole + 1,
    FlyDataAliveRole,
    FlyDataAngleRole,
    FlyDataBirthdayRole,
    FlyDataColorRole,
    FlyDataDescriptionRole,
    FlyDataDestinationRole,
    FlyDataDistanceRole,
    FlyDataDouchenessRole,
    FlyDataIdRole,
    FlyDataLifetimeRole,
    FlyDataPositionRole,
    FlyDataLastRole
};

class FlyDataListModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int count READ count NOTIFY countChanged)

signals:
    void countChanged();
    void added(QList<FlyData>);
    void changed(QList<FlyData>);
    void removed(QList<FlyData>);
    void updated(QList<FlyData>); //added or changed

public:
    explicit FlyDataListModel(const HashedList<FlyData>::FuncPtrHash hash, QObject *parent = 0);

    virtual QHash<int, QByteArray> roleNames() const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    inline int count() const { return this->mData.count(); }
    inline const HashedList<FlyData>& list() const { return this->mData; }
    inline FlyData dataByValue(const FlyData& data) const { const int index = this->mData.indexOf(data); return index >= 0 ? this->mData.at(index) : FlyData(); }
    inline FlyData dataByKey(const QString& key) { const int index = this->mData.indices().value(key, -1); return index >= 0 ? this->mData.at(index) : FlyData(); }
    Q_INVOKABLE inline QModelIndex indexByKey(const QString& key) { const int index = this->mData.indices().value(key, -1); return index >= 0 ? this->index(index) : QModelIndex(); }

public slots:
    Q_INVOKABLE void remove(const FlyData& data);
    Q_INVOKABLE void update(const FlyData& data);
    Q_INVOKABLE void update(const QList<FlyData>&, bool remove = true);

private:
    QMutex mMutex;
    HashedList<FlyData> mData;
};

#endif // FLYDATALISTMODEL_H
