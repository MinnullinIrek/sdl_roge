#include "cell.h"

#include "cell_holder.h"
//#include "visualization_unit.h"


Identifier emptyCell;
Identifier seenCell =
{
  "",
  '.',
  Color{255, 255, 255},
  Color{0, 0, 0},  
};


Cell::Cell() : m_holder(nullptr), m_isSeen(false) {}

Cell::Cell(std::shared_ptr<CellHolder> holder, bool isSeen) : m_holder(holder), m_isSeen(isSeen) {}

Cell::~Cell() {}

Identifier Cell::toIdentifier() const { 

	if (this->m_holder && m_holder->hasIdentifier()) {
		return m_holder->getIdentifier();
	}
	
	return getSeen() ? seenCell : emptyCell;
}

void Cell::setHolder(std::shared_ptr<CellHolder> object) { m_holder = object; }

std::shared_ptr<CellHolder> Cell::getHolder() { return m_holder; }

void Cell::setSeen(bool isSeen) { m_isSeen = isSeen; }

bool Cell::getSeen() const { return m_isSeen; }
