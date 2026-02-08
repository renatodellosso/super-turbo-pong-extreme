#include "stylized_button.h"
#include "utils.h"
#include <godot_cpp/variant/string.hpp>

void StylizedButton::_bind_methods() {}

void StylizedButton::_ready() {
  originalText = get_text();
}

void StylizedButton::_process(double delta) {
  DONT_RUN_IN_EDITOR()

  if (is_hovered()) {
    set_text(vformat("> %s", originalText));
  } else set_text(originalText);
}