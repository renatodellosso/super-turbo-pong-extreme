#include "title_animation.h"
#include <algorithm>
#include "utils.h"

using namespace godot;

TitleAnimation::TitleAnimation() {
  timePassed = 0;
  duration = 5;
  prevIndex = 0;
}

void TitleAnimation::_bind_methods() {
  ClassDB::bind_method(D_METHOD("setDuration", "duration"), &TitleAnimation::setDuration);
  ClassDB::bind_method(D_METHOD("getDuration"), &TitleAnimation::getDuration);
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "duration", PROPERTY_HINT_RANGE, "0,20,0.1"), "setDuration", "getDuration");

  ClassDB::bind_method(D_METHOD("setAudioPlayer", "audioPlayer"), &TitleAnimation::setAudioPlayer);
  ClassDB::bind_method(D_METHOD("getAudioPlayer"), &TitleAnimation::getAudioPlayer);
  ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "audioPlayer", PROPERTY_HINT_NODE_TYPE, "AudioStreamPlayer2D"), "setAudioPlayer", "getAudioPlayer");
}

void TitleAnimation::setDuration(const double duration) {
  this->duration = duration;
}

double TitleAnimation::getDuration() const {
  return duration;
}

void TitleAnimation::setAudioPlayer(AudioStreamPlayer2D* audioPlayer) {
  this->audioPlayer = audioPlayer;
}
AudioStreamPlayer2D* TitleAnimation::getAudioPlayer() const {
  return audioPlayer;
}

void TitleAnimation::_ready() {
  fullText = get_text();
  set_text("");
}

void TitleAnimation::_process(double delta) {
  DONT_RUN_IN_EDITOR()

  timePassed += delta;

  PackedStringArray words = fullText.split(" ");
  int index = floor(MIN(timePassed, duration) / duration * words.size());

  if (index != prevIndex) {
    set_text(String(" ").join(words.slice(0, index)));

    if (audioPlayer != NULL)
    audioPlayer->play();
  }

  prevIndex = index;
}