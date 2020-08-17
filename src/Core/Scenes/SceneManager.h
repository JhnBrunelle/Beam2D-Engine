#pragma once
#include <iostream>
#include <map>
#include <string>
#include "../GameObject.h"

class SceneManager {
public:
    std::map<std::string, GameObject*> ObjectLibrary;       // Library of objects in the library

    // Get object
    GameObject*  GetObject(const std::string &id);

    // Set Object
    void AddObject(const std::string &id, GameObject *go);

};

