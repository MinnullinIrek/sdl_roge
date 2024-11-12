#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "./Component.h"
#include "./EntityManager.h"

class EntityManager;
class Component;

class Entity {
 protected:
  EntityManager& manager;
  bool isActive;
  std::vector<std::shared_ptr<Component>> components;
  std::unordered_map<const std::type_info*, std::shared_ptr<Component>> componentTypeMap;

 public:
  std::string name;
  Entity(EntityManager& manager);
  Entity(EntityManager& manager, std::string_view name);
  void Update(float deltaTime);
  void Render();
  void Destroy();
  bool IsActive() const;

  template <typename T, typename... TArgs>
  T& AddComponent(TArgs&&... args) {
    std::shared_ptr<T> newComponent(new T(std::forward<TArgs>(args)...));
    newComponent->owner = this;
    components.emplace_back(newComponent);
    componentTypeMap[&typeid(T)] = newComponent;
    newComponent->Initialize();
    return *newComponent;
  }

  template <typename T>
  void addComponent(std::shared_ptr<T> newComponent) {
    //std::shared_ptr<T> newComponent(new T(std::forward<TArgs>(args)...));
    newComponent->owner = this;
    components.emplace_back(newComponent);
    
    componentTypeMap[&typeid(T)] = newComponent;
    newComponent->Initialize();
  }
  template <typename T>
  bool HasComponent() const {
    return componentTypeMap.count(&typeid(T));
  }

  template <typename T>
  std::shared_ptr<T> GetComponent() {
    return std::dynamic_pointer_cast<T>(componentTypeMap[&typeid(T)]);
  }
};

#endif
