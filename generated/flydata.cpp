//------------------------------------------------------------------------------
//  This file is auto-generated. Please do not make any changes.
//------------------------------------------------------------------------------
#include "flydata.h"

bool operator !=(const FlyData& left, const FlyData& right)
{
    const bool result(
                ((left.aliveIsNull() != right.aliveIsNull()) || left.alive() != right.alive()) ||
                ((left.angleIsNull() != right.angleIsNull()) || left.angle() != right.angle()) ||
                ((left.birthdayIsNull() != right.birthdayIsNull()) || left.birthday() != right.birthday()) ||
                ((left.destinationIsNull() != right.destinationIsNull()) || left.destination() != right.destination()) ||
                ((left.distanceIsNull() != right.distanceIsNull()) || left.distance() != right.distance()) ||
                ((left.douchenessIsNull() != right.douchenessIsNull()) || left.doucheness() != right.doucheness()) ||
                ((left.idIsNull() != right.idIsNull()) || left.id() != right.id()) ||
                ((left.lifetimeIsNull() != right.lifetimeIsNull()) || left.lifetime() != right.lifetime()) ||
                ((left.positionIsNull() != right.positionIsNull()) || left.position() != right.position()));
    return result;
}

bool operator ==(const FlyData& left, const FlyData& right)
{
    const bool result(!(left != right));
    return result;
}