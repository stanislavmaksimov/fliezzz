#include "flymodel.h"
#include "common.h"
#include <QColor>

QStringList keysOf(const FlyData& value)
{
    return QStringList() << value.id();
}

FlyModel::FlyModel(QObject *parent)
    : FlyDataListModel(&keysOf, parent)
{
}

QVariant FlyModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid()) {
        switch (role) {
        case FlyDataColorRole:
        {
            if (!index.data(FlyDataAliveRole).toBool()) {
                return QColor::fromRgba(qRgba(127, 0, 0, 196));
            }
            const int doucheness = index.data(FlyDataDouchenessRole).toInt();
            const qreal rate = (qreal)(doucheness - Common::DOUCHENESS_MINIMUM) / Common::DOUCHENESS_RANGE;
            return QColor::fromRgba(qRgba(0, (1.0 - rate) * 255, 0, 196));
        }
        case FlyDataDescriptionRole:
        {
            const FlyData data = index.data(FlyDataRole).value<FlyData>();
            return QString("%1; тупость: %2; скорость: %3; пробег: %4; возраст: %5; %6")
                    .arg(data.id())
                    .arg(data.doucheness())
                    .arg(data.lifetime() > 0 ? 1000 * data.distance() / data.lifetime() : 0)
                    .arg(data.distance())
                    .arg(data.lifetime() / 1000)
                    .arg(data.alive() ? "жива" : "сдохла");
        }
        default:
            break;
        }
    }
    return FlyDataListModel::data(index, role);
}
