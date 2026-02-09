#include "main_menu_manager.h"
#include "scene_manager.h"
#include "../utils.h"
#include <godot_cpp/classes/scene_tree.hpp>

void MainMenuManager::_bind_methods() {
  ClassDB::bind_method(D_METHOD("play"), &MainMenuManager::play);
  ClassDB::bind_method(D_METHOD("exitGame"), &MainMenuManager::exitGame);

  ClassDB::bind_method(D_METHOD("setLevelSelectScene"), &MainMenuManager::setLevelSelectScene, "levelSelectScene");
  ClassDB::bind_method(D_METHOD("getLevelSelectScene"), &MainMenuManager::getLevelSelectScene);
  ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "levelSelectScene", PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"), "setLevelSelectScene", "getLevelSelectScene");
}

void MainMenuManager::setLevelSelectScene(Ref<PackedScene> levelSelectScene) {
  this->levelSelectScene = levelSelectScene;
}
Ref<PackedScene> MainMenuManager::getLevelSelectScene() const {
  return levelSelectScene;
}

void MainMenuManager::play() {
  get_tree()->change_scene_to_packed(levelSelectScene);
  // CHANGE_SCENE(SceneIds.BACKSTORY)
}

void MainMenuManager::exitGame() {
  get_tree()->quit();
}