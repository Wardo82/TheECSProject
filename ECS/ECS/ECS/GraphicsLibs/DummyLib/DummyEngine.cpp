//
//  DummyEngine.cpp
//  ECS-proj
//
//  Created by Eduardo Andres Flores Barreto on 10/08/2021.
//

#include "DummyEngine.hpp"
#include "DummyAssetManager.hpp"

#include "EntityManager.h"

DummyEngine::DummyEngine()
 {
    running = false;
    assetManager = nullptr;
}

DummyEngine::~DummyEngine()
{
    
}

void DummyEngine::init()
{
    running = true;
}

void DummyEngine::render()
{

}

void DummyEngine::update()
{
    // manager->refresh();
    // manager->update();
}

void DummyEngine::events(){
    
}

void DummyEngine::clean()
{
    assetManager->clean();
}

