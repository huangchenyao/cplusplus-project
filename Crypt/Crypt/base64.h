#pragma once
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;
class base64
{
private:
	const uint8_t encodeTable[64] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
		'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 
		'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
		'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
	};
	//已知字符，从encodeTable中找序号
	int findChar(uint8_t char64);

public:
	base64();
	~base64();
	//base64编码
	string encode(string &data);
	//base64解码
	string decode(string &base64Str);
};

