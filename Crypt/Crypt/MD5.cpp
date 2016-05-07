#include "MD5.h"


MD5::MD5() {
	for (int i = 1; i <= 64; ++i) {
		t.push_back(uint32_t(4294967296 * abs(sin(i))));
	}
	/*for (auto iter = t.begin(); iter != t.end(); ++iter) {
		cout << hex << *iter << endl;
	}*/
}


MD5::~MD5() {

}

uint32_t MD5::CLS(uint32_t data, uint32_t s) {
	return (data >> (32 - s) | (data << s));
}

uint32_t MD5::CRS(uint32_t data, uint32_t s) {
	return (data << (32 - s) | (data >> s));
}

string MD5::uint32_tToString(uint32_t data) {
	string result;
	for (int i = 0; i < 4; ++i) {
		result += u32ToS[(data & 0x000000f0) >> 4];
		result += u32ToS[data & 0x0000000f];
		data >>= 8;
	}
	return result;
}

void MD5::fill(string &message) {
	uint64_t length = message.length();
	if (length % 64 != 56) {
		message += (char)0x80;
		for (int i = 1; i < 56 - length % 64; ++i) {
			message += (char)0x00;
		}
	}
	length *= 8;
	for (int i = 0; i < 8; ++i) {
		message += (char)((uint64_t)length >> (i * 8));
	}
}

uint32_t MD5::F(uint32_t & X, uint32_t & Y, uint32_t & Z) {
	return (X&Y) | ((~X)&Z);
}

uint32_t MD5::G(uint32_t & X, uint32_t & Y, uint32_t & Z) {
	return (X&Z) | (Y&(~Z));
}

uint32_t MD5::H(uint32_t & X, uint32_t & Y, uint32_t & Z) {
	return X^Y^Z;
}

uint32_t MD5::I(uint32_t & X, uint32_t & Y, uint32_t & Z) {
	return Y ^ (X | (~Z));
}

string MD5::encrypt(string &message) {
	fill(message);
	//四个链接变量的初始值
	uint32_t A = 0x67452301,
		B = 0xefcdab89,
		C = 0x98badcfe,
		D = 0x10325476;

	for (int i = 0; i < message.length() / 64; ++i) {
		vector<uint32_t> M(16, 0);
		for (int j = 0; j < 16; ++j) {
			uint32_t tmp1 = (uint32_t)message[i * 64 + j * 4] & 0x000000ff;
			uint32_t tmp2 = ((uint32_t)message[i * 64 + j * 4 + 1] & 0x000000ff) << 8;
			uint32_t tmp3 = ((uint32_t)message[i * 64 + j * 4 + 2] & 0x000000ff) << 16;
			uint32_t tmp4 = ((uint32_t)message[i * 64 + j * 4 + 3] & 0x000000ff) << 24;
			M[j] = tmp1 | tmp2 | tmp3 | tmp4;
		}
		uint32_t a = A, b = B, c = C, d = D;
		uint32_t f, j;
		for (int i = 0; i < 64; ++i) {
			if (i < 16) {
				f = F(b, c, d);
				j = i;
			}
			else if (i < 32) {
				f = G(b, c, d);
				j = (5 * i + 1) % 16;
			}
			else if (i < 48) {
				f = H(b, c, d);
				j = (3 * i + 5) % 16;
			}
			else {
				f = I(b, c, d);
				j = (7 * i) % 16;
			}
			uint32_t tmp = d;
			d = c;
			c = b;
			b += CLS((a + f + M[j] + t[i]), s[i]);
			a = tmp;
		}
		A += a, B += b, C += c, D += d;
	}
	string result;
	result += uint32_tToString(A);
	result += uint32_tToString(B);
	result += uint32_tToString(C);
	result += uint32_tToString(D);
	//cout << result << endl;
	return result;
}