#ifndef COMMON_H
#define COMMON_H

#include <QDebug>
#include <QThread>

#define LOG qDebug() << QThread::currentThreadId() << Q_FUNC_INFO

class Common
{
public:
    static const int DOUCHENESS_MINIMUM = 100;
    static const int DOUCHENESS_MAXIMUM = 500;
    static const int DOUCHENESS_RANGE = DOUCHENESS_MAXIMUM - DOUCHENESS_MINIMUM;

    static int rand(int max);
    static int randDoucheness();
};

#endif // COMMON_H
