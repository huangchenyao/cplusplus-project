#include "AES.h"
#include <cstdlib>

int main(int argc, char **argv) {
	AES test;
	uint8_t tmp[16] = {
		0x32, 0x88, 0x31, 0xe0,
		0x43, 0x5a, 0x31, 0x37,
		0xf6, 0x30, 0x98, 0x07,
		0xa8, 0x8d, 0xa2, 0x34
	};

	uint8_t key[16] = {
		0x2b, 0x28, 0xab, 0x09,
		0x7e, 0xae, 0xf7, 0xcf,
		0x15, 0xd2, 0x15, 0x4f,
		0x16, 0xa6, 0x88, 0x3c
	};
	uint8_t test1[16] = {
		'0','1','2','3',
		'0','1','2','3',
		'0','1','2','3',
		'0','1','2','3'
	};
	uint8_t test2[16] = {
		'0','1','2','3',
		'0','1','2','3',
		'0','1','2','3',
		'0','1','2','3'
	};
	//test.encrypt16(tmp, key);
	test.encrypt16(test1, test2);
	test.decrypt16(test1, test2);
	system("pause");
	return 0;
}