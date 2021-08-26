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

class DummyAssetManager;

class DummyEngine: public Engine {
    public:
    DummyEngine();
    ~DummyEngine();
    
    void init();
    void clean();
    
    void events();
    void render();
    void update();
    
private:
    DummyAssetManager* assetManager;
};
#endif /* SDLEngine_hpp */
