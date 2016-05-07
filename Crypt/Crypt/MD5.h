#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class MD5
{
private:

	//����t����
	//����̫��̫���ˣ����ǹ����ʱ��ֱ���Զ����ɱȽϷ���
	vector<uint32_t> t;
	//ÿ��ѭ����λ��λ��
	const vector<uint32_t> s = {

		7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
		5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
		6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21

		/*7, 12, 17, 22,
		5,  9, 14, 20,
		4, 11, 16, 23,
		6, 10, 15, 21*/
	};
	//��uint32_t���͵�����ת��Ϊ�ɶ���string��ʽ�����Ҫ�õ��ı�
	const vector<char> u32ToS = {
		'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'
	};

	//Ϊ���Է��㣬�����к������ó�public
//public:
	//ѭ������
	uint32_t CLS(uint32_t data, uint32_t s);
	//ѭ������
	uint32_t CRS(uint32_t data, uint32_t s);
	//��uint32_t���͵�����ת��Ϊ�ɶ���string��ʽ���������0xd8523f60->"603f52d8"
	string uint32_tToString(uint32_t data);
	//��亯��
	void fill(string &message);
	//ÿ�β������õ����ĸ������Ժ�����ÿ��һ����
	uint32_t F(uint32_t &X, uint32_t &Y, uint32_t &Z);
	uint32_t G(uint32_t &X, uint32_t &Y, uint32_t &Z);
	uint32_t H(uint32_t &X, uint32_t &Y, uint32_t &Z);
	uint32_t I(uint32_t &X, uint32_t &Y, uint32_t &Z);

public:
	MD5();
	~MD5();
	//MD5����
	string encrypt(string &message);
};

