#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class MainMenuManager : public Node2D {
  GDCLASS(MainMenuManager, Node2D)

public:
  void exitGame();

protected:
  static void _bind_methods();
};