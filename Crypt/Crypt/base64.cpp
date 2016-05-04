#include "base64.h"



base64::base64()
{
}


base64::~base64()
{
}

uint8_t * base64::encode(uint8_t * data, int length) {
	int length64 = length % 3 ? (length / 3 + 1) * 4 : length / 3 * 4;
	uint8_t * base64Str = new uint8_t[length64];
	int i = 0, j = 0;
	for (; length >= 3; length -= 3) {
		base64Str[j++] = encodeTable[data[i++] >> 2];
		base64Str[j++] = encodeTable[((data[i - 1] & 0x03) << 4) | (data[i++] >> 4)];
		base64Str[j++] = encodeTable[((data[i - 1] & 0x0f) << 2) | (data[i] >> 6)];
		base64Str[j++] = encodeTable[data[i++] & 0x3f];
	}
	if (2 == length) {
		base64Str[j++] = encodeTable[data[i++] >> 2];
		base64Str[j++] = encodeTable[((data[i - 1] & 0x03) << 4) | (data[i++] >> 4)];
		base64Str[j++] = encodeTable[(data[i - 1] & 0x0f) << 2];
		base64Str[j++] = '=';
	}
	if (1 == length) {
		base64Str[j++] = encodeTable[data[i++] >> 2];
		base64Str[j++] = encodeTable[(data[i - 1] & 0x03) << 4];
		base64Str[j++] = '=';
		base64Str[j++] = '=';
	}
	return base64Str;
}

void base64::decode(uint8_t * base64Str, int length64) {

}
