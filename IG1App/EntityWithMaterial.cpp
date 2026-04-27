#include "EntityWithMaterial.h"

EntityWithMaterial::EntityWithMaterial(Material* m): 
    material(m){
}

EntityWithMaterial::~EntityWithMaterial(){
    delete material;
}
