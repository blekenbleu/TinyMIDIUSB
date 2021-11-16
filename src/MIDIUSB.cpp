#include "MIDIUSB.h" // declares the class, among other things

union whatever {
    midiEventPacket_s frick;
    int frack;
} whatever;

midiEventPacket_t CMidiUSB::read(void) {

  whatever.frack = Tmidi.read();
  return whatever.frick;
}
