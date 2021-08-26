//
//  Engine.hpp
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 09/08/2021.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <iostream>

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr int DARK[] = {30, 30, 30, 255};

class Engine {
public:
    
    virtual void init() = 0;
    virtual void clean() = 0;
    
    virtual void events() = 0;
    virtual void render() = 0;
    virtual void update() = 0;
    
    inline bool isRunning() {
        return running;
    }
    
    void quit() {
        running = false;
    }

protected:
    bool running = false;
};

#endif /* Engine_hpp */
