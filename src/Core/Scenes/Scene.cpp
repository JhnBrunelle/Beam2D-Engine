#include "Scene.h"

Scene::Scene(){

}

void Scene::AddObject(const std::string &id, GameObject* go){
    // Add item into the scene
    ObjectLibrary.insert(std::pair<std::string, GameObject*>(id, go));
}


GameObject* Scene::GetObject(const std::string &id){

    //@TODO - add safety for it item is not in MAP
    return ObjectLibrary[id];
}

void Scene::BatchUpdate() {
    std::map<std::string, GameObject*>::iterator itr;
    for (itr =  ObjectLibrary.begin(); itr !=  ObjectLibrary.end(); ++itr) {
        (itr->second)->Update();
    }
}