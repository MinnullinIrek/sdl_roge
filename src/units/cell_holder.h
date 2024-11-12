#ifndef CELLhOLDER_H
#define CELLhOLDER_H

#include <memory>

#include "entity.h"
#include "headers.h"
#include "subscriber.h"
#include "visualization_unit.h"

class IMover;

class CellHolder : public Component, public Publisher {
 public:
  virtual ~CellHolder() {}
  void moved() {}
  Identifier getIdentifier() { return owner->GetComponent<VisualizationUnit>()->getIdentifier(); }
  // std::shared_ptr<IMover> mover;
};

#endif  // CELLhOLDER_H
