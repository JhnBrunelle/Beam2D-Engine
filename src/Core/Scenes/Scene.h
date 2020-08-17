#pragma once
#include "../GameObject.h"
#include <map>

class Scene {
public:
    std::map<std::string, GameObject*> ObjectLibrary;           // Library of objects in the library
    Scene();
    void AddObject(const std::string &id, GameObject* go);      // Add an object to the scene
    GameObject* GetObject(const std::string &id);               // Returns a game object

    // BatchUpdate
    void BatchUpdate();                                         // Update all objects in the scene
};

