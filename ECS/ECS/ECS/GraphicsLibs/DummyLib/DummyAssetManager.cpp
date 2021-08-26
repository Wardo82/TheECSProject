//
//  DummyAssetManager.cpp
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 10/08/2021.
//

#include "DummyAssetManager.hpp"
#include "DummyEngine.hpp"

DummyAssetManager::DummyAssetManager(){
    std::cout << "DummyAssetManager constructor!" << std::endl;
}
    
Texture DummyAssetManager::getTexture(std::string id){
    return (textures.count(id) > 0) ? (textures[id]) : nullptr;
};

void DummyAssetManager::loadTexture(std::string id, std::string path){
    if (textures.count(id) <= 0) {
        textures.emplace(id, path);
        std::cout << "Texture: [" << path << "] loaded!" << std::endl;
    }
};
    
Font DummyAssetManager::getFont(std::string id){
    return (fonts.count(id) > 0) ? (fonts[id]) : nullptr;
};

void DummyAssetManager::loadFont(std::string id, std::string path, int fontSize){
    if (fonts.count(id) <= 0) {
        fonts.emplace(id, path);
        std::cout << "Font: [" << path << "] loaded!" << std::endl;
    }
};

void DummyAssetManager::clean(){
    std::cout << "Assets cleared!" << std::endl;
};

DummyAssetManager::~DummyAssetManager() {
    clean();
};

