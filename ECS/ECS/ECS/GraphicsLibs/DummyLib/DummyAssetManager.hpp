//
//  SDLAssetManager.hpp
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 10/08/2021.
//

#ifndef DummyAssetManager_hpp
#define DummyAssetManager_hpp

#include <stdio.h>
#include "AssetManager.hpp"

using Texture = std::string;
using Font = std::string;

class DummyAssetManager: public AssetManager<Texture, Font>
{
public:
    DummyAssetManager();
    ~DummyAssetManager();

    void clean();
    
    Texture getTexture(std::string id);
    void loadTexture(std::string id, std::string path);
    
    Font getFont(std::string id);
    void loadFont(std::string id, std::string path, int fontSize);
  
private:
    
};


#endif /* DummyAssetManager_hpp */
