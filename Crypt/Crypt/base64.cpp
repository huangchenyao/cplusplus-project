#include "base64.h"



base64::base64()
{
}


base64::~base64()
{
}

void base64::decode(uint8_t * data, int length) {
	int length64 = length % 3 ? length / 3 * 4 : (length / 3 + 1) * 4;
	uint8_t * base64Str = new uint8_t[length];
}

void base64::encode(uint8_t * base64Str, int length64) {

}
