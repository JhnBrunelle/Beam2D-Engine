#include "SceneManager.h"

/**
 * Returns the Scene Library
 * @return ptr to the scene library
 */
std::unordered_map<std::string, Scene *>* SceneManager::GetSceneLibrary() {
    return &SceneLibrary;
}

/**
 * Gets a scene from the Scene Library
 * @return ptr to the scene library
 */
Scene *SceneManager::GetScene(const std::string &id) {
    return SceneLibrary[id];
}

/**
 * Adds a Scene to the Scene Library
 */
void SceneManager::AddScene(const std::string &id, Scene *scene) {
    SceneLibrary.insert(std::pair<std::string, Scene*>(id, scene));

    if(currentScene == nullptr){
        std::cout << "No Scene Set, setting scene just added" << std::endl;

        currentScene = GetScene(id);
    }
}


/**
 * Calls the current active scenes loop
 */
void SceneManager::ActiveSceneLoop() {

    currentScene->SceneLoop();

}

/**
 * Loads a new active scene
 * @param id
 */
void SceneManager::LoadScene(const std::string &id) {
    // Set a new scene
    currentScene = GetScene(id);
}

