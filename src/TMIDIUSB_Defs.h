#pragma once
#include <stdint.h>

struct midiEventPacket_s
{
	uint8_t header;
	uint8_t byte1;
	uint8_t byte2;
	uint8_t byte3;
};

typedef struct midiEventPacket_s midiEventPacket_t;
