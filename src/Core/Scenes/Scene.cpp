#include "Scene.h"

Scene::Scene(){
    // Instance of a Debug Console
    //@TODO - Add macro to remove for prod builds
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

    if(ObjectLibrary.count(id)){
        return ObjectLibrary[id];
    } else {
        db->ErrorMessage("Scene::GetObject(): Attempted to access unknown GameObject - " + id);
    }
}

/**
 * Removes an object from a scene
 * @param id string id of the GameObject to fetch
 * @return ptr to the game object
 */
void Scene::RemoveObject(const std::string &id){

    if(ObjectLibrary.count(id)){
        delete ObjectLibrary[id];
        ObjectLibrary.erase(id);
    } else {
        db->ErrorMessage("Scene::RemoveObject(): Attempted to access unknown GameObject - " + id);
    }

}

/**
 * Calls Update() on all the GameObjects in the map
 * in order that they were added
 */
void Scene::BatchUpdate() {
    std::map<std::string, GameObject*>::iterator itr;
    for (itr =  ObjectLibrary.begin(); itr !=  ObjectLibrary.end(); ++itr) {

        //@TODO - Optimization, update only if needed (static object flag)
        (itr->second)->Update();
    }
}


/**
 * Calls Draw() on all of the GameObjects in order they were added to the map
 */
void Scene::BatchDraw() {
    std::map<std::string, GameObject*>::iterator itr;
    for (itr =  ObjectLibrary.begin(); itr !=  ObjectLibrary.end(); ++itr) {

        (itr->second)->Draw();
    }

    // Draw Error Message if available
    if(db->hasError){
        db->DrawErrorConsole();
    }

}

DebugConsole* Scene::GetDebugConsole() {
    return db;
}