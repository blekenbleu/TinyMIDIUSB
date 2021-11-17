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

#if 0 // defined(ARDUINO_ARCH_AVR)

#define EPTYPE_DESCRIPTOR_SIZE		uint8_t
#define EP_TYPE_BULK_IN_MIDI 		EP_TYPE_BULK_IN
#define EP_TYPE_BULK_OUT_MIDI 		EP_TYPE_BULK_OUT
#define MIDI_BUFFER_SIZE		USB_EP_SIZE
#define is_write_enabled(x)		(1)

#elif defined(ARDUINO_ARCH_SAM)

#define EPTYPE_DESCRIPTOR_SIZE		uint32_t
#define EP_TYPE_BULK_IN_MIDI		(UOTGHS_DEVEPTCFG_EPSIZE_512_BYTE | \
					UOTGHS_DEVEPTCFG_EPDIR_IN |         \
					UOTGHS_DEVEPTCFG_EPTYPE_BLK |       \
					UOTGHS_DEVEPTCFG_EPBK_1_BANK |      \
					UOTGHS_DEVEPTCFG_NBTRANS_1_TRANS |  \
					UOTGHS_DEVEPTCFG_ALLOC)
#define EP_TYPE_BULK_OUT_MIDI       (UOTGHS_DEVEPTCFG_EPSIZE_512_BYTE | \
					UOTGHS_DEVEPTCFG_EPTYPE_BLK |       \
					UOTGHS_DEVEPTCFG_EPBK_1_BANK |      \
					UOTGHS_DEVEPTCFG_NBTRANS_1_TRANS |  \
					UOTGHS_DEVEPTCFG_ALLOC)
#define MIDI_BUFFER_SIZE		EPX_SIZE
#define USB_SendControl			USBD_SendControl
#define USB_Available			USBD_Available
#define USB_Recv			USBD_Recv
#define USB_Send			USBD_Send
#define USB_Flush			USBD_Flush
#define is_write_enabled(x)		Is_udd_write_enabled(x)

#elif defined(ARDUINO_ARCH_SAMD)

#if defined(ARDUINO_API_VERSION)
#define EPTYPE_DESCRIPTOR_SIZE		unsigned int
#else
#define EPTYPE_DESCRIPTOR_SIZE		uint32_t
#endif
#define EP_TYPE_BULK_IN_MIDI 		USB_ENDPOINT_TYPE_BULK | USB_ENDPOINT_IN(0);
#define EP_TYPE_BULK_OUT_MIDI 		USB_ENDPOINT_TYPE_BULK | USB_ENDPOINT_OUT(0);
#define MIDI_BUFFER_SIZE		EPX_SIZE
#define USB_SendControl			USBDevice.sendControl
#define USB_Available			USBDevice.available
#define USB_Recv			USBDevice.recv
#define USB_Send			USBDevice.send
#define USB_Flush			USBDevice.flush
#define is_write_enabled(x)		(1)

//#else

//#error "Unsupported architecture"

#endif


#endif	/* MIDIUSB_h */
