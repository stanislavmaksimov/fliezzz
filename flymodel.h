#ifndef FLYMODEL_H
#define FLYMODEL_H

#include "flydatalistmodel.h"

class FlyModel : public FlyDataListModel
{
    Q_OBJECT

public:
    explicit FlyModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // FLYMODEL_H
