#include "base64.h"



base64::base64()
{
}


base64::~base64()
{
}

string base64::encode(string &data) {
	string base64Str;
	int i = 0;
	int length = data.length();
	for (; length >= 3; length -= 3, i += 3) {
		base64Str += encodeTable[data[i] >> 2];
		base64Str += encodeTable[((data[i] & 0x03) << 4) | (data[i + 1] >> 4)];
		base64Str += encodeTable[((data[i + 1] & 0x0f) << 2) | (data[i + 2] >> 6)];
		base64Str += encodeTable[data[i + 2] & 0x3f];
	}
	if (2 == length) {
		base64Str += encodeTable[data[i] >> 2];
		base64Str += encodeTable[((data[i] & 0x03) << 4) | (data[i + 1] >> 4)];
		base64Str += encodeTable[(data[i + 1] & 0x0f) << 2];
		base64Str += '=';
	}
	if (1 == length) {
		base64Str += encodeTable[data[i] >> 2];
		base64Str += encodeTable[(data[i] & 0x03) << 4];
		base64Str += '=';
		base64Str += '=';
	}
	return base64Str;
}

string base64::decode(string &base64Str) {
	for (int i = 0; i < 2; ++i) {
		if ('=' == base64Str.back()) {
			base64Str.pop_back();
		}
	}
	for (int i = 0; i < base64Str.length(); ++i) {
		base64Str[i] = findChar(base64Str[i]);
	}

	string data;
	int i = 0;
	int length = base64Str.length();
	for (; length >= 4; length -= 4, i += 4) {
		data += (base64Str[i] << 2) | (base64Str[i + 1] >> 4);
		data += (base64Str[i + 1] << 4) | (base64Str[i + 2] >> 2);
		data += (base64Str[i + 2] << 6) | base64Str[i + 3];
	}
	if (3 == length) {
		data += (base64Str[i] << 2) | (base64Str[i + 1] >> 4);
		data += (base64Str[i + 1] << 4) | (base64Str[i + 2] >> 2);
	}
	if (2 == length) {
		data += (base64Str[i] << 2) | (base64Str[i + 1] >> 4);

	}
	return data;
}

int base64::findChar(uint8_t char64) {
	for (int i = 0; i < 64; ++i) {
		if (encodeTable[i] == char64) {
			return i;
		}
	}
	return -1;
}