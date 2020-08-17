#pragma once
#include "../GameObject.h"
#include <map>

class Scene {
public:
    std::map<std::string, GameObject*> ObjectLibrary;           // Library of objects in the library
    Scene();
    void AddObject(const std::string &id, GameObject* go);      // Add an object to the scene
    void RemoveObject(const std::string &id);                   // Removes an object from the scene
    GameObject* GetObject(const std::string &id);               // Returns a game object

    // Batch operations
    void BatchUpdate();                                         // Update all objects in the scene
    void BatchDraw();
};

