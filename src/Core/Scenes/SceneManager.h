#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Scene.h"

class SceneManager {
public:
    std::unordered_map<std::string, Scene*> SceneLibrary;       // Library of Scenes in the library

};

