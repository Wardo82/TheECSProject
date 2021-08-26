//
//  AssetManager.h
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 03/08/2021.
//

#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <iostream>
#include <map>
#include <string>

template <typename Texture, typename Font>
class AssetManager {
public:
    AssetManager(){};
    virtual ~AssetManager(){};
    
    virtual void clean() = 0;
    
    virtual Texture getTexture(std::string id) = 0;
    virtual void loadTexture(std::string id, std::string path) = 0;
    
    virtual Font getFont(std::string id) = 0;
    virtual void loadFont(std::string id, std::string path, int fontSize) = 0;
    
    
protected:
    std::map<std::string, Texture> textures;
    std::map<std::string, Font> fonts;
};

#endif /* AssetManager_h */
