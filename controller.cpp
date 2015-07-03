#include "controller.h"
#include "fly.h"
#include "flydata.h"
#include "flymodel.h"
#include "common.h"

Controller::Controller(QObject *parent)
    : QObject(parent)
    , mSize(10)
    , mCapacity(3)
    , mModel(new FlyModel(this))
{
    LOG;
}

void Controller::setSize(int value)
{
    if (this->mSize != value) {
        this->mSize = value;
        LOG << this->mSize;
        emit this->sizeChanged(this->mSize);
    }
}

void Controller::setCapacity(int value)
{
    if (this->mCapacity != value) {
        this->mCapacity = value;
        LOG << this->mCapacity;
        emit this->capacityChanged(this->mCapacity);
    }
}

void Controller::addFly(const QPoint& position)
{
    QMutexLocker locker(&this->mMutex);
    Q_UNUSED(locker);

    if (this->isCellAvailable(position)) {
        if (Fly* fly = new Fly(position, this)) {
            connect(fly, SIGNAL(tryMove(FlyData&)), this, SLOT(onFlyTryMove(FlyData&)), Qt::DirectConnection);
            connect(fly, SIGNAL(changed(FlyData)), this->mModel, SLOT(update(FlyData)));
            fly->start();
        }
    }
}

void Controller::onFlyTryMove(FlyData& value)
{
    QMutexLocker locker(&this->mMutex);
    Q_UNUSED(locker);

    LOG << value.id();
    value.setAlive(value.doucheness() * this->mSize > value.lifetime() / 10);
    if (this->isCellAvailable(value.destination())) {
        value.setPosition(value.destination());
    }
}

bool Controller::isCellAvailable(const QPoint& value) const
{
    const bool outOfRange = value.x() < 0
            || value.y() < 0
            || value.x() > this->mSize - 1
            || value.y() > this->mSize - 1;
    if (!outOfRange) {
        const QModelIndexList indices = this->mModel->match(
                    this->mModel->index(0),
                    FlyDataPositionRole,
                    value,
                    -1,
                    Qt::MatchExactly);
        return indices.count() < this->mCapacity;
    }
    return false;
}

QAbstractItemModel* Controller::model() const
{
    return this->mModel;
}
