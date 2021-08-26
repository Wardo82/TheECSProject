//
//  SDLAssetManager.cpp
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 10/08/2021.
//

#include "SDLAssetManager.hpp"
#include "SDLEngine.hpp"

SDLAssetManager::SDLAssetManager(SDL_Renderer* renderer){
    if (TTF_Init() != 0) {
        std::cerr << TTF_GetError() << std::endl;
    }
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0){
        std::cerr << TTF_GetError() << std::endl;
    }
    renderer = renderer;
}

TexturePtr SDLAssetManager::getTexture(std::string id){
    return (textures.count(id) > 0) ? textures[id] : nullptr;
};

void SDLAssetManager::loadTexture(std::string id, std::string path){
    if (textures.count(id) <= 0) {
        SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
        if(texture) {
            textures.emplace(id, texture);
            std::cout << "Texture: [" << path << "] loaded!" << std::endl;
        }
        else
            std::cerr << IMG_GetError() << std::endl;
    }
};
   
FontPtr SDLAssetManager::getFont(std::string id){
    return (fonts.count(id) > 0) ? fonts[id] : nullptr;
};

void SDLAssetManager::loadFont(std::string id, std::string path, int fontSize){
    TTF_Font* font = TTF_OpenFont(path.c_str(), fontSize);
    if (font != nullptr) {
        fonts.emplace(id, font);
        std::cout << "Font: [" << path << "] loaded!" << std::endl;
    }
    else
        std::cerr << TTF_GetError() << std::endl;
};

void SDLAssetManager::clean(){
    // Clean textures
    for (auto it = textures.begin(); it != textures.end(); it++) {
        SDL_DestroyTexture(it->second);
        textures.erase(it);
    }
    textures.clear();
    // Clean fonts
    for (auto it = fonts.begin(); it != fonts.end(); it++) {
        TTF_CloseFont(it->second);
        fonts.erase(it);
    }
    fonts.clear();
    std::cout << "Assets cleared!" << std::endl;
};

SDLAssetManager::~SDLAssetManager() {
    clean();
};

