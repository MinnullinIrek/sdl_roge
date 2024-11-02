#include "./EntityManager.h"

void EntityManager::ClearData() {
    for (auto& entity: entities) {
        entity->Destroy();
    }
}

bool EntityManager::hasNoEntities() {
    return entities.empty();
}

void EntityManager::Update(float deltaTime) {
    for (auto& entity: entities) {
        entity->Update(deltaTime);
    }
}

void EntityManager::render() {
    for (auto& entity: entities) {
        entity->Render();
    }
}

Entity& EntityManager::AddEntity(std::string_view entityName) {
  std::shared_ptr<Entity> entity (new Entity(*this, entityName));
    entities.emplace_back(entity);
    return *entity;
}

std::vector<std::shared_ptr<Entity>> EntityManager::GetEntities() const {
    return entities;
}

unsigned int EntityManager::GetEntityCount() const {
    return entities.size();
}
