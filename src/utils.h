#pragma once

#include <godot_cpp/classes/engine.hpp>

#define DONT_RUN_IN_EDITOR() if (Engine::get_singleton()->is_editor_hint()) \
    return;