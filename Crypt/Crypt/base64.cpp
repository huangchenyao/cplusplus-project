#include "base64.h"



base64::base64()
{
}


base64::~base64()
{
}

vector<uint8_t> base64::encode(vector<uint8_t> &data) {
	vector<uint8_t> base64Str;
	int i = 0;
	int length = data.size();
	for (; length >= 3; length -= 3, i += 3) {
		base64Str.push_back(encodeTable[data[i] >> 2]);
		base64Str.push_back(encodeTable[((data[i] & 0x03) << 4) | (data[i + 1] >> 4)]);
		base64Str.push_back(encodeTable[((data[i + 1] & 0x0f) << 2) | (data[i + 2] >> 6)]);
		base64Str.push_back(encodeTable[data[i + 2] & 0x3f]);
	}
	if (2 == length) {
		base64Str.push_back(encodeTable[data[i] >> 2]);
		base64Str.push_back(encodeTable[((data[i] & 0x03) << 4) | (data[i + 1] >> 4)]);
		base64Str.push_back(encodeTable[(data[i + 1] & 0x0f) << 2]);
		base64Str.push_back('=');
	}
	if (1 == length) {
		base64Str.push_back(encodeTable[data[i] >> 2]);
		base64Str.push_back(encodeTable[(data[i] & 0x03) << 4]);
		base64Str.push_back('=');
		base64Str.push_back('=');
	}
	return base64Str;
}

vector<uint8_t> base64::decode(vector<uint8_t> &base64Str) {
	for (int i = 0; i < 2; ++i) {
		if ('=' == base64Str.back()) {
			base64Str.pop_back();
		}
	}
	for (auto iter = base64Str.begin(); iter != base64Str.end(); ++iter) {
		*iter = findChar(*iter);
	}
	
	vector<uint8_t> data;
	int i = 0;
	int length = base64Str.size();
	for (; length >= 4; length -= 4, i += 4) {
		data.push_back((base64Str[i] << 2) | (base64Str[i + 1] >> 4));
		data.push_back((base64Str[i + 1] << 4) | (base64Str[i + 2] >> 2));
		data.push_back((base64Str[i + 2] << 6) | base64Str[i + 3]);
	}
	if (3 == length) {
		data.push_back((base64Str[i] << 2) | (base64Str[i + 1] >> 4));
		data.push_back((base64Str[i + 1] << 4) | (base64Str[i + 2] >> 2));
	}
	if (2 == length) {
		data.push_back((base64Str[i] << 2) | (base64Str[i + 1] >> 4));
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