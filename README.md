# TinyMIDIUSB
 fake Arduino USBMIDI sketches to use ESP32TinyUSB  

MIDIusb is the class for ESP32TinyUSB, declared in `ESP32TinyUSB/src/midiusb.h`  
MidiUSB is wanted in `USB-MIDI.h` and `USB-MIDI_defs.h`  
`MIDIusb MidiUSB;` gets error 'MIDIusb' does not name a type in MIDIUSB.h;  
   - don't know why; it works in midi.ino..?  

`#define MidiUSB MIDIusb` gets error 'midiEventPacket_t' does not name a type  
      in USB-MIDI\src/USB-MIDI.h, so *relative* progress  

### Arduino has its own `midiusb.h`
`class TMidiUSB:public MIDIusb` gets error `expected class-name before '{' token`,  
	but `class MidiUSB:public EspTinyUSB` is accepted..??!   
renamed libraries/ESP32TinyUSB/src/midiusb.h to libraries/ESP32TinyUSB/src/Tmidiusb.h
