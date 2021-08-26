//
//  SDLEngine.hpp
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 10/08/2021.
//

#ifndef SDLEngine_hpp
#define SDLEngine_hpp

#include <stdio.h>
#include "Engine.hpp"
#include "SDL.h"

class SDLAssetManager;

class SDLEngine: public Engine {
    public:
    SDLEngine();
    ~SDLEngine();
    
    void init();
    void clean();
    
    void events();
    void render();
    void update();
    
    inline SDL_Renderer* getRenderer(){
        return renderer;
    }
    
private:
    SDLAssetManager* assetManager;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
};
#endif /* SDLEngine_hpp */
