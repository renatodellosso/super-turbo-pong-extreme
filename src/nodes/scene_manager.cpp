#include "scene_manager.h"

void SceneManager::_bind_methods() {
  ClassDB::bind_method(D_METHOD("setAvailableScenes"), &SceneManager::setAvailableScenes, "availableScenes");
  ClassDB::bind_method(D_METHOD("getAvailableScenes"), &SceneManager::getAvailableScenes);
  ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "availableScenes"), "setAvailableScenes", "getAvailableScenes");

  ClassDB::bind_method(D_METHOD("setCurrentScene"), &SceneManager::setCurrentScene, "scene");
  ClassDB::bind_method(D_METHOD("getCurrentScene"), &SceneManager::getCurrentScene);
  ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "currentScene", PROPERTY_HINT_NODE_TYPE, "Node2D"), "setCurrentScene", "getCurrentScene");

  ClassDB::bind_method(D_METHOD("changeScene"), &SceneManager::changeScene, "newScene");
}

void SceneManager::setAvailableScenes(Dictionary availableScenes) {
  this->availableScenes = availableScenes;
}

Dictionary SceneManager::getAvailableScenes() const {
  return availableScenes;
}
 
void SceneManager::setCurrentScene(Node2D* scene) {
  currentScene = scene;
}

Node2D* SceneManager::getCurrentScene() {
  return currentScene;
}

Node2D* SceneManager::changeScene(String newSceneId) {
  Object* newSceneObj = availableScenes.get(newSceneId, nullptr);
  if (!newSceneObj) {
    print_error("Invalid scene ID: ", newSceneId);
    return nullptr;
  }

  print_line("Setting scene to ", newSceneId);

  Node2D* newScene = static_cast<Node2D*>(newSceneObj);
  auto old = currentScene;

  remove_child(old);
  add_child(newScene);
  currentScene = newScene;

  return old;
}