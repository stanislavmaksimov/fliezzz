#include "common.h"
#include <QtGlobal>
#include <QDateTime>

int Common::rand(int max)
{
    static bool RAND_INITIALIZED = false;
    if (!RAND_INITIALIZED) {
        qsrand(QDateTime::currentDateTime().toTime_t());
        RAND_INITIALIZED = true;
    }
    return qrand() % max;
}

int Common::randDoucheness()
{
    return DOUCHENESS_MINIMUM + rand(DOUCHENESS_RANGE);
}
