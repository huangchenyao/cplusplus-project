#pragma once
#include <cstdint>
class base64
{
public:
	base64();
	~base64();
	void encode(uint8_t *data, int length);
	void decode(uint8_t *base64Str, int length);
};

