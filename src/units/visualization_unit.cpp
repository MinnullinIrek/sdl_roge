#include "visualization_unit.h"

VisualizationUnit::VisualizationUnit(Identifier id) : Component(), m_id(id) {}

VisualizationUnit::~VisualizationUnit() {}

Identifier VisualizationUnit::getIdentifier() { return m_id; }
void VisualizationUnit::getIdentifier(const Identifier& id) { m_id = id; }
