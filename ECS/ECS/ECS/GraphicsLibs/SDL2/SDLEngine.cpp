//
//  SDLEngine.cpp
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 10/08/2021.
//

#include "SDLEngine.hpp"
#include "SDLAssetManager.hpp"

#include "EntityManager.h"

SDLEngine::SDLEngine()
 {
    running = false;
    assetManager = nullptr;
    window = nullptr;
    renderer = nullptr;
}

SDLEngine::~SDLEngine()
{
    
}

void SDLEngine::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    }
    
    if (SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    }
    
    assetManager = new SDLAssetManager(renderer);
    
    running = true;

    std::cout << "SDL Engine initialized" << std::endl;
}

void SDLEngine::render()
{
    SDL_SetRenderDrawColor(renderer, DARK[0], DARK[1], DARK[2], DARK[3]);
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
}

void SDLEngine::update()
{
    // manager->refresh();
    // manager->update();
}

void SDLEngine::events(){
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        running = false;
    }
}

void SDLEngine::clean()
{
    assetManager->clean();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

