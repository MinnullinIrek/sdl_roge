#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component {
 public:
  Entity* owner = nullptr;
  virtual ~Component() = default;
  virtual void Initialize() {}
  virtual void Update(float deltaTime) {}
  virtual void Render() {}
};

#endif
