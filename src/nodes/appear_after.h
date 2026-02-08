#pragma once

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/audio_stream_player2d.hpp>

using namespace godot;

class AppearAfter : public Control {
	GDCLASS(AppearAfter, Control)

public:
	AppearAfter();
	~AppearAfter() override = default;

  void setDuration(const double duration);
  double getDuration() const;

  void setAudioPlayer(AudioStreamPlayer2D* audioPlayer);
  AudioStreamPlayer2D* getAudioPlayer() const;

  void _ready() override;
  void _process(double delta) override;

protected:
	static void _bind_methods();

private:
  double duration;
  AudioStreamPlayer2D* audioPlayer;

  double timePassed;
};