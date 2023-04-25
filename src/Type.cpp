#include "Type.h"

bool Type::numeric(Type &p)
{
    if (p == gtypeChar || p == gtypeInt || p == gtypeFloat)
        return true;
    else
        return false;
}

Type Type::max(Type &p1, Type &p2)
{
    if (!numeric(p1) || !numeric(p2))
        return gtypeNone;
    else if (p1 == gtypeFloat || p2 == gtypeFloat)
        return gtypeFloat;
    else if (p1 == gtypeInt || p2 == gtypeInt)
        return gtypeInt;
    else
        return gtypeChar;
}
