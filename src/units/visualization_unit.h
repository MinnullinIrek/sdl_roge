#pragma once

#include <memory>

#include "entity.h"
#include "headers.h"
#include "subscriber.h"


class VisualizationUnit : public Component {
 public:
  VisualizationUnit() = default;
  VisualizationUnit(Identifier id);
  ~VisualizationUnit();

  Identifier getIdentifier();
  void getIdentifier(const Identifier& id);

 private:
  Identifier m_id;
};
