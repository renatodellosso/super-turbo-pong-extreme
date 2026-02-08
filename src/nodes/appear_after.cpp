#include "appear_after.h"
#include "utils.h"
#include <algorithm>

using namespace godot;

AppearAfter::AppearAfter() {
  timePassed = 0;
  duration = 5;

  SKIP_ON_INPUT_CONSTRUCTOR
}

void AppearAfter::_bind_methods() {
  ClassDB::bind_method(D_METHOD("setDuration", "duration"), &AppearAfter::setDuration);
  ClassDB::bind_method(D_METHOD("getDuration"), &AppearAfter::getDuration);
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "duration", PROPERTY_HINT_RANGE, "0,20,0.1"), "setDuration", "getDuration");

  ClassDB::bind_method(D_METHOD("setAudioPlayer", "audioPlayer"), &AppearAfter::setAudioPlayer);
  ClassDB::bind_method(D_METHOD("getAudioPlayer"), &AppearAfter::getAudioPlayer);
  ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "audioPlayer", PROPERTY_HINT_NODE_TYPE, "AudioStreamPlayer2D"), "setAudioPlayer", "getAudioPlayer");

  SKIP_ON_INPUT_BIND(AppearAfter)
}

void AppearAfter::setDuration(const double duration) {
  this->duration = duration;
}

double AppearAfter::getDuration() const {
  return duration;
}

void AppearAfter::setAudioPlayer(AudioStreamPlayer2D* audioPlayer) {
  this->audioPlayer = audioPlayer;
}
AudioStreamPlayer2D* AppearAfter::getAudioPlayer() const {
  return audioPlayer;
}

void AppearAfter::_ready() {
  set_visible(false);
}

void AppearAfter::_process(double delta) {
  DONT_RUN_IN_EDITOR()

  double newTime = timePassed + delta;

  if (timePassed < duration && newTime > duration) {
    set_visible(true);

    if (audioPlayer != NULL)
      audioPlayer->play();
  }

  timePassed = newTime;
}

SKIP_ON_INPUT_TRIGGER(AppearAfter)

void AppearAfter::skip() {
  set_visible(true);
  timePassed = duration;
}