#include "main_menu_manager.h"
#include "scene_manager.h"
#include "../utils.h"
#include <godot_cpp/classes/scene_tree.hpp>

void MainMenuManager::_bind_methods() {
  ClassDB::bind_method(D_METHOD("play"), &MainMenuManager::play);
  ClassDB::bind_method(D_METHOD("exitGame"), &MainMenuManager::exitGame);
}

void MainMenuManager::play() {
  CHANGE_SCENE(SceneIds.BACKSTORY)
}

void MainMenuManager::exitGame() {
  get_tree()->quit();
}