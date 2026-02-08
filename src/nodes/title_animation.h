#pragma once

#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/audio_stream_player2d.hpp>

using namespace godot;

class TitleAnimation : public Label {
	GDCLASS(TitleAnimation, Label)

public:
	TitleAnimation();
	~TitleAnimation() override = default;

  void setFullText(const String fullText);
  String getFullText() const;

  void setDuration(const double duration);
  double getDuration() const;

  void setAudioPlayer(AudioStreamPlayer2D* audioPlayer);
  AudioStreamPlayer2D* getAudioPlayer() const;

  void _ready() override;
  void _process(double delta) override;

protected:
	static void _bind_methods();

private:
  String fullText;
  double duration;

  AudioStreamPlayer2D* audioPlayer;

  double timePassed;
  int prevIndex;
};