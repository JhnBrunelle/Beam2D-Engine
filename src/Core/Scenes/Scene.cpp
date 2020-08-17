#include "Scene.h"

Scene::Scene(){
    // Instance of DEBUG console
   db = new DebugConsole();
}

/**
 * Adds an object to the scene library
 * @param id string title of the id
 * @param go ptr to the GameObject add
 */
void Scene::AddObject(const std::string &id, GameObject* go){
    // Add item into the scene
    ObjectLibrary.insert(std::pair<std::string, GameObject*>(id, go));
}

/**
 * Get Object
 * @param id string id of the GameObject to fetch
 * @return ptr to the game object
 */
GameObject* Scene::GetObject(const std::string &id){

    //@TODO - add safety for it item is not in MAP
    return ObjectLibrary[id];
}

/**
 * Removes an object from a scene
 * @param id string id of the GameObject to fetch
 * @return ptr to the game object
 */
void Scene::RemoveObject(const std::string &id){

    //@TODO - add safety for it item is not in MAP
    delete ObjectLibrary[id];
    ObjectLibrary.erase(id);
}

/**
 * Calls all the Updates in the scene
 */
void Scene::BatchUpdate() {
    std::map<std::string, GameObject*>::iterator itr;
    for (itr =  ObjectLibrary.begin(); itr !=  ObjectLibrary.end(); ++itr) {

        //@TODO - Optimization, update only if needed (static object flag)
        (itr->second)->Update();
    }
}


void Scene::BatchDraw() {
    std::map<std::string, GameObject*>::iterator itr;
    for (itr =  ObjectLibrary.begin(); itr !=  ObjectLibrary.end(); ++itr) {

        (itr->second)->Draw();
    }

    // Draw Error Message
    if(db->hasError){
        std::cout << "I've been drawn!" << std::endl;
        db->DrawErrorConsole();
    }

}

DebugConsole* Scene::GetDebugConsole() {
    return db;
}