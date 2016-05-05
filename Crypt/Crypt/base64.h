#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
class base64
{
private:
	uint8_t encodeTable[64] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
		'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 
		'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
		'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
	};
public:
	base64();
	~base64();
	vector<uint8_t> encode(vector<uint8_t> data, int length);
	vector<uint8_t> decode(vector<uint8_t> base64Str, int length);
};

