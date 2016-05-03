#include "AES.h"

AES::AES() {

}

AES::~AES() {

}

uint8_t AES::multi(uint8_t a, uint8_t b) {
	uint8_t result = 0x00;
	for (int i = 8; i > 0; --i) {
		if (b & 0x80) {
			uint8_t tmp = a;
			for (int j = 0; j < i - 1; ++j) {
				if (tmp & 0x80) {
					tmp <<= 1;
					tmp ^= 0x1b;
				}
				else {
					tmp <<= 1;
				}
			}
			result ^= tmp;
		}
		b <<= 1;
	}
	return result;
}

void AES::multiMatrix(uint8_t *a, uint8_t *b, uint8_t *result, int m, int p, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			*(result + i * 4 + j) = 0x00;
			for (int k = 0; k < p; ++k) {
				*(result + i * 4 + j) ^= multi(*(a + i * 4 + k), *(b + k * 4 + j));
			}
		}
	}
}

void AES::subBytes(uint8_t *state) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int row = (*(state + i * 4 + j) & 0xf0) >> 4;
			int col = *(state + i * 4 + j) & 0x0f;
			*(state + i * 4 + j) = sBox[row][col];
		}
	}
}

void AES::invSubBytes(uint8_t *state) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int row = (*(state + i * 4 + j) & 0xf0) >> 4;
			int col = *(state + i * 4 + j) & 0x0f;
			*(state + i * 4 + j) = invSBox[row][col];
		}
	}
}

void AES::shiftRows(uint8_t *state) {
	uint8_t *tmp = new uint8_t[3 * 4];
	for (int i = 1; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			*(tmp + (i - 1) * 4 + j) = *(state + i * 4 + j);
		}
		for (int j = 0; j < 4; ++j) {
			*(state + i * 4 + j) = *(tmp + (i - 1) * 4 + (j + i) % 4);
		}
	}
	delete[] tmp;
}

void AES::invShiftRows(uint8_t *state) {
	uint8_t *tmp = new uint8_t[3 * 4];
	for (int i = 1; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			*(tmp + (i - 1) * 4 + j) = *(state + i * 4 + j);
		}
		for (int j = 0; j < 4; ++j) {
			*(state + i * 4 + j) = *(tmp + (i - 1) * 4 + (4 + j - i) % 4);
		}
	}
	delete[] tmp;
}

void AES::mixColumns(uint8_t *state) {
	uint8_t *tmp = new uint8_t[4 * 4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			*(tmp + i * 4 + j) = *(state + i * 4 + j);
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			*(state + i * 4 + j) = 0x00;
			for (int k = 0; k < 4; ++k) {
				*(state + i * 4 + j) ^= multi(mixCol[i][k], *(tmp + k * 4 + j));
			}
		}
	}
	delete[] tmp;
}

void AES::invMixColumns(uint8_t *state) {
	uint8_t *tmp = new uint8_t[4 * 4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			*(tmp + i * 4 + j) = *(state + i * 4 + j);
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			*(state + i * 4 + j) = 0x00;
			for (int k = 0; k < 4; ++k) {
				*(state + i * 4 + j) ^= multi(invMixCol[i][k], *(tmp + k * 4 + j));
			}
		}
	}
	delete[] tmp;
}

void AES::addRoundKey(uint8_t *state, uint8_t *roundKey) {
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 4; ++i) {
			*(state + i * 4 + j) ^= *(roundKey + i * 4 + j);
		}
	}
}

void AES::keySchedule(uint8_t *key) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			roundKey[0][i * 4 + j] = *(key + i * 4 + j);
		}
	}
	for (int i = 1; i < 11; ++i) {
		//First 32bits
		//Wi-1 root word
		uint8_t tmp = roundKey[i - 1][0 * 4 + 3];
		roundKey[i][0 * 4 + 0] = roundKey[i - 1][1 * 4 + 3];
		roundKey[i][1 * 4 + 0] = roundKey[i - 1][2 * 4 + 3];
		roundKey[i][2 * 4 + 0] = roundKey[i - 1][3 * 4 + 3];
		roundKey[i][3 * 4 + 0] = tmp;
		//S-box
		for (int k = 0; k < 4; ++k) {
			int row = (roundKey[i][k * 4 + 0] & 0xf0) >> 4;
			int col = roundKey[i][k * 4 + 0] & 0x0f;
			roundKey[i][k * 4 + 0] = sBox[row][col];
		}
		//XOR with RC and Wi-4
		roundKey[i][0 * 4 + 0] = roundKey[i][0 * 4 + 0] ^ roundKey[i - 1][0 * 4 + 0] ^ RC[i];
		roundKey[i][1 * 4 + 0] = roundKey[i][1 * 4 + 0] ^ roundKey[i - 1][1 * 4 + 0] ^ 0x00;
		roundKey[i][2 * 4 + 0] = roundKey[i][2 * 4 + 0] ^ roundKey[i - 1][2 * 4 + 0] ^ 0x00;
		roundKey[i][3 * 4 + 0] = roundKey[i][3 * 4 + 0] ^ roundKey[i - 1][3 * 4 + 0] ^ 0x00;
		//Leftover
		//Wi equal Wi-1 XOR Wi-4
		for (int j = 1; j < 4; ++j) {
			roundKey[i][0 * 4 + j] = roundKey[i][0 * 4 + j - 1] ^ roundKey[i - 1][0 * 4 + j];
			roundKey[i][1 * 4 + j] = roundKey[i][1 * 4 + j - 1] ^ roundKey[i - 1][1 * 4 + j];
			roundKey[i][2 * 4 + j] = roundKey[i][2 * 4 + j - 1] ^ roundKey[i - 1][2 * 4 + j];
			roundKey[i][3 * 4 + j] = roundKey[i][3 * 4 + j - 1] ^ roundKey[i - 1][3 * 4 + j];
		}
	}
}

void AES::show16(uint8_t *state) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << "0x" << hex << (int)*(state + i * 4 + j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void AES::encrypt16(uint8_t *state, uint8_t *key) {
	keySchedule(key);
	addRoundKey(state, roundKey[0]);
	//round 1~9
	for (int i = 1; i < 10; ++i) {
		//cout << "round key" << endl;
		//show16(roundKey[i]);
		subBytes(state);
		//cout << "sub: " << endl;
		//show16(state);
		shiftRows(state);
		//cout << "shift: " << endl;
		//show16(state);
		mixColumns(state);
		//cout << "mix: " << endl;
		//show16(state);
		addRoundKey(state, roundKey[i]);
		//cout << "xor: " << endl;
		//show16(state);
	}
	//round 10
	//cout << "round key" << endl;
	//show16(roundKey[10]);
	subBytes(state);
	shiftRows(state);
	addRoundKey(state, roundKey[10]);
	//cout << "xor: " << endl;
	show16(state);
}

void AES::decrypt16(uint8_t *state, uint8_t *key) {
	//round 10
	addRoundKey(state, roundKey[10]);
	invShiftRows(state);
	invSubBytes(state);
	//round 9~1
	for (int i = 9; i > 0; --i) {	
		addRoundKey(state, roundKey[i]);
		invMixColumns(state);
		invShiftRows(state);
		invSubBytes(state);
	}
	addRoundKey(state, roundKey[0]);
	show16(state);
}

