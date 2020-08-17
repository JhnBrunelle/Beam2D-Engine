#include "SceneManager.h"



void SceneManager::AddObject(const std::string &id, GameObject* go){
    // Add item into the scene
    ObjectLibrary.insert(std::pair<std::string, GameObject*>(id, go));
}


GameObject* SceneManager::GetObject(const std::string &id){

    //@TODO - add safety for it item is not in MAP
    return ObjectLibrary[id];
}