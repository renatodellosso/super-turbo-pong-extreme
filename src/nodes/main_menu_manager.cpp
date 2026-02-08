#include "main_menu_manager.h"
#include <godot_cpp/classes/scene_tree.hpp>

void MainMenuManager::_bind_methods() {
  ClassDB::bind_method(D_METHOD("exitGame"), &MainMenuManager::exitGame);
}

void MainMenuManager::exitGame() {
  get_tree()->quit();
}