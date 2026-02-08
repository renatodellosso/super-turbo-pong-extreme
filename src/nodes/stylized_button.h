#pragma once

#include <godot_cpp/classes/button.hpp>

using namespace godot;

class StylizedButton : public Button {
	GDCLASS(StylizedButton, Button)

public:
	StylizedButton() = default;
	~StylizedButton() override = default;

  void _ready() override;
  void _process(double delta) override;

protected:
	static void _bind_methods();

private:
  String originalText;
};