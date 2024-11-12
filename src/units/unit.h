#ifndef UNITS_H
#define UNITS_H

#include "headers.h"
#include "cell_holder.h"
#include "component.h"

class IUnit : public Name, public CellHolder {
 public:
  IUnit() = default;
 ~IUnit() = default;
};

#endif // UNITS_H
