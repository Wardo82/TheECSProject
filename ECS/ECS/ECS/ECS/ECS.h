#pragma once

#include <array>
#include <bitset>
#include <iostream>

class Entity;
class Component;

/* Component ID custom type and static getters. */
using ComponentTypeID = std::size_t;

/* Returns a different ID each time it is called for a component */
inline ComponentTypeID getUniqueComponentID() {
	static ComponentTypeID lastID = 0u;
	return lastID++;
}

/* Returns the same ID each time it is called for a given Component type. */
template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept {
	static_assert(std::is_base_of<Component, T>::value, "getComponentTypeID: Type not based on Component class.");
	static const ComponentTypeID typeID = getUniqueComponentID();
	return typeID;
}

// Constant expresions
constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentList = std::array<Component*, MAX_COMPONENTS>;
