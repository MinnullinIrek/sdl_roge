#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <memory>
#include "./EntityManager.h"
#include "./Component.h"

class EntityManager;
class Component;

class Entity {
    private:
        EntityManager& manager;
        bool isActive;
        std::vector<std::shared_ptr<Component>> components;
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
            newComponent->Initialize();
            return *newComponent;
        }
};

#endif
