#pragma once

#include <godot_cpp/classes/engine.hpp>
#include "nodes/scene_manager.h"

#define DONT_RUN_IN_EDITOR() if (Engine::get_singleton()->is_editor_hint()) \
  return;

#define CHANGE_SCENE(sceneId) \
  if (get_parent_class_static() != StringName("SceneManager")) { \
    print_error("Parent is not a SceneManager!"); \
    return; \
  } \
\
  SceneManager* parent = static_cast<SceneManager*>(get_parent()); \
  parent->changeScene(SceneIds.BACKSTORY);