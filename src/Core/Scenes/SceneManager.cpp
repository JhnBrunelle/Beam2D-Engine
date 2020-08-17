#include "SceneManager.h"

/**
 * Returns the Scene Library
 * @return ptr to the scene library
 */
std::unordered_map<std::string, Scene *>* SceneManager::GetSceneLibrary() {
    return &SceneLibrary;
}

Scene *SceneManager::GetScene(const std::string &id) {
    return SceneLibrary[id];
}

void SceneManager::AddScene(const std::string &id, Scene *scene) {
    SceneLibrary.insert(std::pair<std::string, Scene*>(id, scene));

}

