/*
  Alternative MIDI USB class
*/
#ifndef TinyMIDIUSB_h
#define TinyMIDIUSB_h

#include "esptinyusb.h"        // Esp32TinyUSB/src
#include "MIDIUSB_Defs.h"      // MIDIUSB/src/
#include "Tmidiusb.h"		// Esp32TinyUSB/src/

// glue MIDI_Library to ESP32TinyUSB
//class CMidiUSB:public MIDIusb
class CMidiUSB			// Esp32TinyUSB alternative to MidiUSB
{
  MIDIusb Tmidi;		// instance Esp32TinyUSB object

  public:
    size_t sendMIDI(midiEventPacket_t buffer) { return 1; }
    midiEventPacket_t read(void);
    void flush(void) { return; }
};
extern CMidiUSB MidiUSB;	// USB-MIDI/src/*.h expects this instance
#define USBCON			// enable MIDI_Library/examples
#define MIDIUSB_H		// disable Arduino MIDIUSB's src/MIDIUSB.h
#define USB_MIDI_H		// disable Arduino USBMIDI's src/usbmidi.h
#include "USB-MIDI.h"		// transport layer

// MIDIusb is the class for ESP32TinyUSB;
// CMidiUSB will use MIDIusb
#define TUSBMIDI_CREATE_DEFAULT_INSTANCE() \
USBMIDI_CREATE_DEFAULT_INSTANCE(); \
MIDIusb Tmidi; \
CMidiUSB MidiUSB

#endif	/* MIDIUSB_h */
