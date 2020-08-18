#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Scene.h"

class SceneManager {
private:
    std::unordered_map<std::string, Scene*> SceneLibrary;       // Library of Scenes in the library
public:
    Scene* currentScene = nullptr;
    std::unordered_map<std::string, Scene*>* GetSceneLibrary(); // Returns the Scene Library

    // Scene Library editing functions
    Scene* GetScene(const std::string &id);
    void AddScene(const std::string &id, Scene *scene);

    void ActiveSceneLoop();

    void LoadScene(const std::string &id);
};

