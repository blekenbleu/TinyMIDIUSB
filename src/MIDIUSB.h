/*
  Alternative Arduino MIDI USB class using Esp32TinyUSB
*/
#ifndef TinyMIDIUSB_h
#define TinyMIDIUSB_h

#include "esptinyusb.h"		// Esp32TinyUSB/src
#include "TMIDIUSB_Defs.h"	// MIDIUSB/src/
#include "Tmidiusb.h"		// Esp32TinyUSB/src/

// ESP32TinyUSB wrapper for MIDI_Library
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
#define noteOn	sendNoteOn
#define noteOff	sendNoteOff

// CMidiUSB uses MIDIusb, a class from ESP32TinyUSB.
#define TinyUSBMIDI_CREATE_DEFAULT_INSTANCE() \
USBMIDI_CREATE_DEFAULT_INSTANCE(); \
MIDIusb Tmidi; \
CMidiUSB MidiUSB

#endif	/* MIDIUSB_h */
