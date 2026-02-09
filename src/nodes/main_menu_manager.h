#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;

class MainMenuManager : public Node2D {
  GDCLASS(MainMenuManager, Node2D)

public:
  MainMenuManager();
  ~MainMenuManager() = default;

  void setLevelSelectScene(Ref<PackedScene> levelSelectScene);
  Ref<PackedScene> getLevelSelectScene() const;

  void play();
  void exitGame();

protected:
  static void _bind_methods();

private:
  Ref<PackedScene> levelSelectScene;
};