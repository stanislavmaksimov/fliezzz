#ifndef FLY_H
#define FLY_H

#include <QThread>
#include "flydata.h"

class Fly : public QThread
{
    Q_OBJECT

signals:
    void tryMove(FlyData&);
    void changed(const FlyData&);

public:
    explicit Fly(const QPoint& position = QPoint(), QObject *parent = 0);
    ~Fly();

    const FlyData& data() const;

protected:
    void run();

private slots:
    void update(const FlyData&);
    void doSomething();

private:
    FlyData mData;
};

#endif // FLY_H
