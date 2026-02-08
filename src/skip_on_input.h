#pragma once

#include <godot_cpp/classes/input_event.hpp>

#define SKIP_ON_INPUT_H \
public: \
  void setSkipOnInput(const bool skipOnInput) { \
    this->skipOnInput = skipOnInput; \
  } \
  bool getSkipOnInput() const { \
    return skipOnInput; \
  } \
\
  void _input(const Ref<InputEvent>& event) override; \
\
private: \
  bool skipOnInput; \
  void skip(); \

#define SKIP_ON_INPUT_CONSTRUCTOR \
  skipOnInput = true;

#define SKIP_ON_INPUT_BIND(Class) \
  ClassDB::bind_method(D_METHOD("setSkipOnInput", "skipOnInput"), &Class::setSkipOnInput); \
  ClassDB::bind_method(D_METHOD("getSkipOnInput"), &Class::getSkipOnInput); \
  ADD_PROPERTY(PropertyInfo(Variant::BOOL, "skipOnInput"), "setSkipOnInput", "getSkipOnInput");

#define SKIP_ON_INPUT_TRIGGER(Class) \
void Class::_input(const Ref<InputEvent>& event) { \
  if (skipOnInput && event->is_action("skip")) \
    skip(); \
}