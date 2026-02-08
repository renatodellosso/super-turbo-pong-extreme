#pragma once

#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

const struct {
  const char* MAIN_MENU;
  const char* BACKSTORY;
} SceneIds = {
  .MAIN_MENU = "mainMenu",
  .BACKSTORY = "backstory"
};

class SceneManager : public Node2D {
  GDCLASS(SceneManager, Node2D)

public:
  void setAvailableScenes(Dictionary availableScenes);
  Dictionary getAvailableScenes() const;

  void setCurrentScene(Node2D* scene);
  Node2D* getCurrentScene();

  /**
   * Returns the old scene
   */
  Node2D* changeScene(String newSceneId);

protected:
  static void _bind_methods();

private:
  Dictionary availableScenes;
  Node2D* currentScene;
};