#pragma once

#include <memory>
#include <unordered_map>

#include "component.h"

//class Interactor : public Component {
// public:
//  void operator()(std::shared_ptr<Interactor> interactor);
//  virtual void interact(std::shared_ptr<Interactor> interactor) = 0;
//};
//
//class UnitInteractor : public Interactor {
// public:
//  void interact(std::shared_ptr<Interactor> interactor) override;
//  std::unordered_map<int, EUnitType> comandTypes;
//  int commandNum = 0;
//};
