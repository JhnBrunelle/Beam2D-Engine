#pragma once
#include "../GameObject.h"
#include "../Utils/DebugConsole.h"
#include <map>

class Scene {
private:
    DebugConsole *db;                                           // ptr to the debug console
    std::map<std::string, GameObject*> ObjectLibrary;           // Library of objects in the library

public:
    Scene();                                                    // Default constructor
    void AddObject(const std::string &id, GameObject* go);      // Add an object to the scene
    void RemoveObject(const std::string &id);                   // Removes an object from the scene
    GameObject* GetObject(const std::string &id);               // Returns a game object

    // Batch operations
    void BatchUpdate();                                         // Update all objects in the scene
    void BatchDraw();                                           // Draw all objects in the scene

    // Getters
    DebugConsole* GetDebugConsole();                            // Return private Debug console

    virtual void SceneLoop();                                           // Game loop per scene
};

