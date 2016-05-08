#include "AES.h"
#include "base64.h"
#include "MD5.h"
#include <cstdlib>

int main(int argc, char **argv) {
	AES aesCrypt;
	base64 base64Crypt;
	MD5 md5Crypt;

	string a = aesCrypt.encryptECB((string)"1111222233334444", (string)"1111222233334444");
	cout << a << endl;
	cout << aesCrypt.decryptECB(a, (string)"1111222233334444") << endl;
	

	//string tmp = "abcde";
	//cout << md5Crypt.encrypt(tmp) << endl;

	system("pause");
	return 0;
}