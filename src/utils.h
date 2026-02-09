#pragma once

#include <godot_cpp/classes/engine.hpp>
#include "nodes/scene_manager.h"

#define DONT_RUN_IN_EDITOR() if (Engine::get_singleton()->is_editor_hint()) \
  return;

#define CHANGE_SCENE(sceneId) \
  print_line("Attempting to change scene to ", sceneId); \
  Node* parent = get_parent(); \
  if (!parent) { \
    print_error("Parent is not a SceneManager because it is null!"); \
    return; \
  } \
\
  if (parent->get_class() != StringName("SceneManager")) { \
    print_error("Parent is not a SceneManager! It is a: %s", parent->get_class()); \
    return; \
  } \
\
  SceneManager* sceneManager = static_cast<SceneManager*>(parent); \
  sceneManager->changeScene(SceneIds.BACKSTORY);