#include "CompoundEntity.h"

CompoundEntity::~CompoundEntity() {
    for (int i = 0; i < gObjects.size(); i++) {
        delete gObjects[i];
    }
}

void CompoundEntity::addEntity(Abs_Entity* ae) {
    gObjects.push_back(ae);
}

void CompoundEntity::update() {
    for (auto& entity : gObjects) {
        entity->update();
    }
}

void CompoundEntity::load() {
    for (auto& entity : gObjects) {
        entity->load();
    }
}

void CompoundEntity::unload() {
    for (auto& entity : gObjects) {
        entity->unload();
    }
}

void CompoundEntity::render(const glm::mat4& modelViewMat) const {
    glm::mat4 aMat = modelViewMat * mModelMat;
    for (auto& entity : gObjects) {
        entity->render(aMat);
    }
}