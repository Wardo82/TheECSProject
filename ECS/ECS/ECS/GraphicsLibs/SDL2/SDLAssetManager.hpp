//
//  SDLAssetManager.hpp
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 10/08/2021.
//

#ifndef SDLAssetManager_hpp
#define SDLAssetManager_hpp

#include <stdio.h>
#include "AssetManager.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

using TexturePtr = SDL_Texture*;
using FontPtr = TTF_Font*;

class SDLAssetManager: public AssetManager<TexturePtr, FontPtr>
{
public:
    SDLAssetManager(SDL_Renderer *renderer);
    ~SDLAssetManager();

    void clean();
    
    TexturePtr getTexture(std::string id);
    void loadTexture(std::string id, std::string path);
    
    FontPtr getFont(std::string id);
    void loadFont(std::string id, std::string path, int fontSize);
  
private:
    SDLAssetManager() {};
    SDL_Renderer *renderer;
};


#endif /* SDLAssetManager_hpp */
