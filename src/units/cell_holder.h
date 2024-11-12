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
  Identifier getIdentifier() const { return owner->GetComponent<VisualizationUnit>()->getIdentifier(); }
  bool hasIdentifier() const { return owner->HasComponent<VisualizationUnit>(); }
};

#endif  // CELLhOLDER_H
