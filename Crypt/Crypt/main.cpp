#include "AES.h"
#include "base64.h"
#include "MD5.h"
#include <cstdlib>
#include <iomanip>
int main(int argc, char **argv) {
	AES aesCrypt;
	base64 base64Crypt;
	MD5 md5Crypt;
	/*
		vector<uint8_t> key = {
			0x2b, 0x28, 0xab, 0x09,
			0x7e, 0xae, 0xf7, 0xcf,
			0x15, 0xd2, 0x15, 0x4f,
			0x16, 0xa6, 0x88, 0x3c
		};

		vector<uint8_t> tmp = {
			0x32, 0x88, 0x31, 0xe0,
			0x43, 0x5a, 0x31, 0x37,
			0xf6, 0x30, 0x98, 0x07,
			0xa8, 0x8d, 0xa2, 0x34
		};

		vector<uint8_t> test1 = {
			'0','1','2','3','4'
		};
		vector<uint8_t> test2 = {
			'0','1','2','3',
			'0','1','2','3',
			'0','1','2','3',
			'0','1','2','3'
		};*/

		/*vector<uint8_t> result = base64Crypt.encode(test1);
		for (auto iter = result.begin(); iter != result.end(); ++iter) {
			cout << *iter;
		}

		vector<uint8_t> test3 = base64Crypt.decode(result);
		for (auto iter = test3.begin(); iter != test3.end(); ++iter) {
			cout << *iter;
		}*/
		//aesCrypt.encryptECB(tmp, tmp.size(), key);
		//aesCrypt.decryptECB(tmp, tmp.size(), key);
	string tmp = "abcde";
	cout << md5Crypt.encrypt(tmp) << endl;

	system("pause");
	return 0;
}