#include "CompoundEntity.h"
#include "Light.h"

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
    for (Abs_Entity* entity : gObjects) {
        entity->unload();
    }
    for (Texture* texture : gTextures) {
        delete texture;
    }
    for (Light* light : gLights) {
        delete light;
    }
    unloadLights();
}

void CompoundEntity::render(const glm::mat4& modelViewMat) const {
    glm::mat4 aMat = modelViewMat * mModelMat;
    uploadLights(aMat);
    for (auto& entity : gObjects) {
        entity->render(aMat);
    }
}

void CompoundEntity::uploadLights(glm::mat4& aMat) const {
    Shader* shader = Shader::get("light");
    shader->use();
    for (Light* el : gLights) {
        el->upload(*shader, aMat);
    }
}

void CompoundEntity::unloadLights() const {
    Shader* shader = Shader::get("light");
    shader->use();
    for (Light* l : gLights) {
        l->unload(*shader);
    }
}