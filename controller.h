#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMutex>

class FlyData;
class FlyModel;
class QAbstractItemModel;

class Controller : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int size MEMBER mSize WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(int capacity MEMBER mCapacity WRITE setCapacity NOTIFY capacityChanged)
    Q_PROPERTY(QAbstractItemModel* model READ model CONSTANT)

signals:
    void sizeChanged(int);
    void capacityChanged(int);

public:
    explicit Controller(QObject *parent = 0);

    Q_INVOKABLE void addFly(const QPoint&);

private slots:
    void setSize(int);
    void setCapacity(int);

    void onFlyTryMove(FlyData&);

private:
    bool isCellAvailable(const QPoint&) const;
    QAbstractItemModel* model() const;

    int mSize;
    int mCapacity;
    FlyModel* mModel;
    QMutex mMutex;
};

#endif // CONTROLLER_H
