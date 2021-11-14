# TinyMIDIUSB
 fake Arduino USBMIDI sketches to use ESP32TinyUSB  

MIDIusb is the class for ESP32TinyUSB, declared in `ESP32TinyUSB/src/midiusb.h`  
MidiUSB is wanted in `USB-MIDI.h` and `USB-MIDI_defs.h`  
`MIDIusb MidiUSB;` gets error 'MIDIusb' does not name a type in MIDIUSB.h;  
   - don't know why; it works in midi.ino..?  

`#define MidiUSB MIDIusb` gets error 'midiEventPacket_t' does not name a type  
      in USB-MIDI\src/USB-MIDI.h, so *relative* progress  

### Arduino has its own `midiusb.h`?
`class TMidiUSB:public MIDIusb` gets error `expected class-name before '{' token`,  
	but `class MidiUSB:public EspTinyUSB` is accepted..??!   
renamed libraries/ESP32TinyUSB/src/midiusb.h to libraries/ESP32TinyUSB/src/Tmidiusb.h

`USBMIDI_CREATE_DEFAULT_INSTANCE` is defined in libraries/USB-MIDI/src/USB-MIDI.h  
as USBMIDI_CREATE_INSTANCE(0, MIDI)

#### downlevel Arduino SD 1.8.16 library
/c/Users/bleke/Documents/Arduino/hardware/espressif/esp32/libraries/SD is version 2.0.0;
/d/packages/Arduino/arduino-1.8.16/libraries/SD/library.properties is version 1.2.4
```
bleke@ALIENWARE-R7 MSYS /c/Users/bleke/Documents/Arduino/hardware/espressif/esp32/libraries
$ cd /d/packages/Arduino/arduino-1.8.16/libraries

bleke@ALIENWARE-R7 MSYS /d/packages/Arduino/arduino-1.8.16/libraries
$ mv SD ..
```

#### 11/14/2021: compiles, but does not link  
Need cMidiUSB.cpp to create e.g. MidiUSB.read() from ESP32TinyUSB read()  

