//------------------------------------------------------------------------------
//  This file is auto-generated. Please do not make any changes.
//------------------------------------------------------------------------------
#ifndef FLYDATA_H
#define FLYDATA_H

#include <QDateTime>
#include <QList>
#include <QMetaType>
#include <QPoint>
#include <QString>

class FlyData
{
    bool mAlive;
    bool mAliveIsNull;
    int mAngle;
    bool mAngleIsNull;
    QDateTime mBirthday;
    bool mBirthdayIsNull;
    QPoint mDestination;
    bool mDestinationIsNull;
    int mDistance;
    bool mDistanceIsNull;
    int mDoucheness;
    bool mDouchenessIsNull;
    QString mId;
    bool mIdIsNull;
    int mLifetime;
    bool mLifetimeIsNull;
    QPoint mPosition;
    bool mPositionIsNull;

public:
    FlyData()
        : mAlive(false)
        , mAliveIsNull(true)
        , mAngle(0)
        , mAngleIsNull(true)
        , mBirthday(QDateTime())
        , mBirthdayIsNull(true)
        , mDestination()
        , mDestinationIsNull(true)
        , mDistance(0)
        , mDistanceIsNull(true)
        , mDoucheness(0)
        , mDouchenessIsNull(true)
        , mId(QString::null)
        , mIdIsNull(true)
        , mLifetime(0)
        , mLifetimeIsNull(true)
        , mPosition()
        , mPositionIsNull(true)
    {
    }

    FlyData(const FlyData& copy)
        : mAlive(copy.mAlive)
        , mAliveIsNull(copy.mAliveIsNull)
        , mAngle(copy.mAngle)
        , mAngleIsNull(copy.mAngleIsNull)
        , mBirthday(copy.mBirthday)
        , mBirthdayIsNull(copy.mBirthdayIsNull)
        , mDestination(copy.mDestination)
        , mDestinationIsNull(copy.mDestinationIsNull)
        , mDistance(copy.mDistance)
        , mDistanceIsNull(copy.mDistanceIsNull)
        , mDoucheness(copy.mDoucheness)
        , mDouchenessIsNull(copy.mDouchenessIsNull)
        , mId(copy.mId)
        , mIdIsNull(copy.mIdIsNull)
        , mLifetime(copy.mLifetime)
        , mLifetimeIsNull(copy.mLifetimeIsNull)
        , mPosition(copy.mPosition)
        , mPositionIsNull(copy.mPositionIsNull)
    {
    }

    virtual ~FlyData() {}

    inline bool aliveIsNull() const { return this->mAliveIsNull; }
    inline bool alive() const { return this->mAlive; }
    virtual inline bool setAlive(bool value)
    {
        this->mAliveIsNull = false;
        if (this->mAlive != value)
        {
            this->mAlive = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetAlive()
    {
        const bool value = bool();
        this->mAliveIsNull = true;
        if (this->mAlive != value)
        {
            this->mAlive = value;
            return true;
        }
        return false;
    }

    inline bool angleIsNull() const { return this->mAngleIsNull; }
    inline int angle() const { return this->mAngle; }
    virtual inline bool setAngle(int value)
    {
        this->mAngleIsNull = false;
        if (this->mAngle != value)
        {
            this->mAngle = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetAngle()
    {
        const int value = int();
        this->mAngleIsNull = true;
        if (this->mAngle != value)
        {
            this->mAngle = value;
            return true;
        }
        return false;
    }

    inline bool birthdayIsNull() const { return this->mBirthdayIsNull; }
    inline QDateTime birthday() const { return this->mBirthday; }
    virtual inline bool setBirthday(QDateTime value)
    {
        this->mBirthdayIsNull = false;
        if (this->mBirthday != value)
        {
            this->mBirthday = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetBirthday()
    {
        const QDateTime value = QDateTime();
        this->mBirthdayIsNull = true;
        if (this->mBirthday != value)
        {
            this->mBirthday = value;
            return true;
        }
        return false;
    }

    inline bool destinationIsNull() const { return this->mDestinationIsNull; }
    inline QPoint destination() const { return this->mDestination; }
    virtual inline bool setDestination(QPoint value)
    {
        this->mDestinationIsNull = false;
        if (this->mDestination != value)
        {
            this->mDestination = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetDestination()
    {
        const QPoint value = QPoint();
        this->mDestinationIsNull = true;
        if (this->mDestination != value)
        {
            this->mDestination = value;
            return true;
        }
        return false;
    }

    inline bool distanceIsNull() const { return this->mDistanceIsNull; }
    inline int distance() const { return this->mDistance; }
    virtual inline bool setDistance(int value)
    {
        this->mDistanceIsNull = false;
        if (this->mDistance != value)
        {
            this->mDistance = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetDistance()
    {
        const int value = int();
        this->mDistanceIsNull = true;
        if (this->mDistance != value)
        {
            this->mDistance = value;
            return true;
        }
        return false;
    }

    inline bool douchenessIsNull() const { return this->mDouchenessIsNull; }
    inline int doucheness() const { return this->mDoucheness; }
    virtual inline bool setDoucheness(int value)
    {
        this->mDouchenessIsNull = false;
        if (this->mDoucheness != value)
        {
            this->mDoucheness = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetDoucheness()
    {
        const int value = int();
        this->mDouchenessIsNull = true;
        if (this->mDoucheness != value)
        {
            this->mDoucheness = value;
            return true;
        }
        return false;
    }

    inline bool idIsNull() const { return this->mIdIsNull; }
    inline QString id() const { return this->mId; }
    virtual inline bool setId(QString value)
    {
        this->mIdIsNull = false;
        if (this->mId != value)
        {
            this->mId = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetId()
    {
        const QString value = QString();
        this->mIdIsNull = true;
        if (this->mId != value)
        {
            this->mId = value;
            return true;
        }
        return false;
    }

    inline bool lifetimeIsNull() const { return this->mLifetimeIsNull; }
    inline int lifetime() const { return this->mLifetime; }
    virtual inline bool setLifetime(int value)
    {
        this->mLifetimeIsNull = false;
        if (this->mLifetime != value)
        {
            this->mLifetime = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetLifetime()
    {
        const int value = int();
        this->mLifetimeIsNull = true;
        if (this->mLifetime != value)
        {
            this->mLifetime = value;
            return true;
        }
        return false;
    }

    inline bool positionIsNull() const { return this->mPositionIsNull; }
    inline QPoint position() const { return this->mPosition; }
    virtual inline bool setPosition(QPoint value)
    {
        this->mPositionIsNull = false;
        if (this->mPosition != value)
        {
            this->mPosition = value;
            return true;
        }
        return false;
    }
    virtual inline bool resetPosition()
    {
        const QPoint value = QPoint();
        this->mPositionIsNull = true;
        if (this->mPosition != value)
        {
            this->mPosition = value;
            return true;
        }
        return false;
    }

    virtual inline bool reset()
    {
        bool changed = false;
        changed |= this->resetAlive();
        changed |= this->resetAngle();
        changed |= this->resetBirthday();
        changed |= this->resetDestination();
        changed |= this->resetDistance();
        changed |= this->resetDoucheness();
        changed |= this->resetId();
        changed |= this->resetLifetime();
        changed |= this->resetPosition();
        return changed;
    }

    bool merge(const FlyData& other)
    {
        bool changed = false;
        if (!other.aliveIsNull()) changed |= this->setAlive(other.alive());
        if (!other.angleIsNull()) changed |= this->setAngle(other.angle());
        if (!other.birthdayIsNull()) changed |= this->setBirthday(other.birthday());
        if (!other.destinationIsNull()) changed |= this->setDestination(other.destination());
        if (!other.distanceIsNull()) changed |= this->setDistance(other.distance());
        if (!other.douchenessIsNull()) changed |= this->setDoucheness(other.doucheness());
        if (!other.idIsNull()) changed |= this->setId(other.id());
        if (!other.lifetimeIsNull()) changed |= this->setLifetime(other.lifetime());
        if (!other.positionIsNull()) changed |= this->setPosition(other.position());
        return changed;
    }
};

bool operator !=(const FlyData& left, const FlyData& right);
bool operator ==(const FlyData& left, const FlyData& right);

typedef QList<FlyData> FlyDataList;

Q_DECLARE_METATYPE(FlyData)
Q_DECLARE_METATYPE(FlyDataList)

#endif // FLYDATA_H
