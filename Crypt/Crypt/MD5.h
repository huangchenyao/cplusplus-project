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

	//常数t数组
	//数据太烦太多了，还是构造的时候直接自动生成比较方便
	vector<uint32_t> t;
	//每次循环移位的位数
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
	//把uint32_t类型的数据转化为可读的string形式输出需要用到的表
	const vector<char> u32ToS = {
		'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'
	};

	//为测试方便，把所有函数设置成public
//public:
	//循环左移
	uint32_t CLS(uint32_t data, uint32_t s);
	//循环右移
	uint32_t CRS(uint32_t data, uint32_t s);
	//把uint32_t类型的数据转化为可读的string形式输出，例如0xd8523f60->"603f52d8"
	string uint32_tToString(uint32_t data);
	//填充函数
	void fill(string &message);
	//每次操作中用到的四个非线性函数（每轮一个）
	uint32_t F(uint32_t &X, uint32_t &Y, uint32_t &Z);
	uint32_t G(uint32_t &X, uint32_t &Y, uint32_t &Z);
	uint32_t H(uint32_t &X, uint32_t &Y, uint32_t &Z);
	uint32_t I(uint32_t &X, uint32_t &Y, uint32_t &Z);

public:
	MD5();
	~MD5();
	//MD5加密
	string encrypt(string &message);
};

