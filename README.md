## TinyMIDIUSB - fake MIDIUSB Library for Arduino
 Glue transport layer [USB-MIDI](https://github.com/lathoub/Arduino-USBMIDI)
to [ESP32TinyUSB](https://www.arduino.cc/reference/en/libraries/esp32tinyusb)  
This should support [Control Surface](https://github.com/tttapa/Control-Surface),
which is *extensively* documented.   

MIDIusb is the class for ESP32TinyUSB, declared in `ESP32TinyUSB/src/midiusb.h`  
MidiUSB is wanted in `USB-MIDI.h` and `USB-MIDI_defs.h`  
`MIDIusb MidiUSB;` declaration gets error: `'MIDIusb' does not name a type in MIDIUSB.h`;  
   - don't know why; it works in midi.ino..?  

`#define MidiUSB MIDIusb` gets error 'midiEventPacket_t' does not name a type  
      in USB-MIDI\src/USB-MIDI.h, so *relative* progress  

### Arduino has its own `midiusb.h`?
`class TMidiUSB:public MIDIusb` gets error: `expected class-name before '{' token`,  
	but `class MidiUSB:public EspTinyUSB` is accepted..??!   
Arduino evidently `ignores` `midiusb.h` contents!!?  
In `libraries/ESP32TinyUSB/src/`, renamed midiusb.h to **T**midiusb.h as a work-around.  

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

#### 11/14/2021: compiles and links 
Even though only `read()` is [implemented](src/MIDIUSB.cpp)...
-  where are `write()`'s going?
