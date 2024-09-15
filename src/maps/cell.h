#ifndef CELL_H
#define CELL_H

#include <memory>

// #include "../header.h"
#include "coords.h"

class CellHolder;

class Cell : public ToIdentifier {
public:
  Cell(const Coord &coord, std::shared_ptr<CellHolder> holder, bool isSeen);
  ~Cell();

  Identifier toIdentifier() const override;
  void setHolder(std::shared_ptr<CellHolder> object);
  std::shared_ptr<CellHolder> getHolder();
  void setSeen(bool isSeen);
  bool getSeen();

protected:
  Coord m_coord;
  std::shared_ptr<CellHolder> m_holder;
  bool m_isSeen = false;
};

#endif
