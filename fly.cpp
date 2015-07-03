#include "fly.h"
#include "common.h"
#include <QCryptographicHash>

const QList<QPoint> DIRECTIONS = QList<QPoint>()
        << QPoint(-1, -1)
        << QPoint(0, -1)
        << QPoint(1, -1)
        << QPoint(1, 0)
        << QPoint(1, 1)
        << QPoint(0, 1)
        << QPoint(-1, 1)
        << QPoint(-1, 0);

const QList<int> ANGLES = QList<int>()
        << -45
        << 0
        << 45
        << 90
        << 135
        << 180
        << -135
        << -90;

Fly::Fly(const QPoint& position, QObject *parent)
    : QThread(parent)
    , mData()
{
    qRegisterMetaType<FlyData>("FlyData");

    static int ID_COUNTER = 0;

    FlyData data;
    data.setAlive(true);
    data.setBirthday(QDateTime::currentDateTime());
    data.setDoucheness(Common::randDoucheness());
    data.setId(QString::number(++ID_COUNTER));
    data.setPosition(position);
    this->update(data);
    LOG << this->mData.id() << this->mData.doucheness();
}

Fly::~Fly()
{
    if (this->isRunning()) {
        this->requestInterruption();
        this->wait();
    }
    LOG << this->mData.id();
}

void Fly::run()
{
    LOG << "started";
    emit this->changed(this->mData);
    while (!this->isInterruptionRequested() && this->mData.alive()) {
        const QDateTime loopStartTime = QDateTime::currentDateTime();
        while (!this->isInterruptionRequested() && loopStartTime.msecsTo(QDateTime::currentDateTime()) < this->mData.doucheness()) {
            /*LOG << "thinking about something" << */
            QCryptographicHash::hash(this->mData.id().toUtf8(), QCryptographicHash::Sha256).toHex();
        }
        if (!this->isInterruptionRequested()) {
            this->doSomething();
        }
    }
    LOG << "stopped";
}

const FlyData& Fly::data() const
{
    return this->mData;
}

void Fly::update(const FlyData& value)
{
    if (this->mData.merge(value)) {
        LOG << this->mData.id();
        emit this->changed(this->mData);
    }
}

void Fly::doSomething()
{
    const QDateTime currentDateTime = QDateTime::currentDateTime();
    FlyData data = this->mData;
    data.setLifetime(data.birthday().msecsTo(currentDateTime));
    const int direction = Common::rand(DIRECTIONS.count() - 1);
    const QPoint offset = DIRECTIONS.at(direction);
    const QPoint destination = data.position() + offset;
    data.setDestination(destination);
    data.setAngle(ANGLES.at(direction));
    emit this->tryMove(data);
    if (!data.alive()) {
        this->requestInterruption();
    } else {
        data.setDistance(this->mData.distance() + offset.manhattanLength());
    }
    this->update(data);
}
