#include <iostream>

#include "GraphicsLibs/SDL2/SDLEngine.hpp"

int main(int argc, char *argv[])
{
	std::cout << "Starting ECS Project" << std::endl;
    
    std::unique_ptr<SDLEngine> engine(new SDLEngine());
    engine->init();
    
    while (engine->isRunning()) {
        engine->events();
        engine->update();
        engine->render();
    }

    engine->clean();
    
	return 0;
}
