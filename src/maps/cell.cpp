#include "cell.h"
#include "cell_holder.h"

Identifier emptyCell;

Cell::Cell(const Coord &coord, std::shared_ptr<CellHolder> holder, bool isSeen)
    : m_coord(coord), m_holder(holder), m_isSeen(isSeen) {}

Cell::~Cell() {}

Identifier Cell::toIdentifier() const { return emptyCell; }

void Cell::setHolder(std::shared_ptr<CellHolder> object) { m_holder = object; }

std::shared_ptr<CellHolder> Cell::getHolder() { return m_holder; }

void Cell::setSeen(bool isSeen) { m_isSeen = isSeen; }

bool Cell::getSeen() { return m_isSeen; }
