/*!
    \file      hj30.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ30 字符串合并处理
    \version   1.0
    \date      2021-11-10

    \copyright Copyright (C) 2021 Archlizix

    \note      选择排序算法实现错位排序。
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>

void sort01(std::string &str)
{
	for (int i = 0, n = str.size(); i < n - 1; i += 2) {
		for (int j = i + 2; j < n; j += 2) {
			if (str[i] > str[j]) {
				std::swap(str[i], str[j]);
			}
		}
	}
	for (int i = 1, n = str.size(); i < n - 1; i += 2) {
		for (int j = i + 2; j < n; j += 2) {
			if (str[i] > str[j]) {
				std::swap(str[i], str[j]);
			}
		}
	}
}

char reverse01(char ch)
{
	int num;
	if ('0' <= ch && ch <= '9') {
		num = ch - '0';
	} else if ('a' <= ch && ch <= 'f') {
		num = ch - 'a' + 10;
	} else if ('A' <= ch && ch <= 'F') {
		num = ch - 'A' + 10;
	} else {
		return ch;
	}
	int num_new = 0;
	for (int i = 0; i < 4; ++i) {
		num_new = (num_new << 1) + (num & 1u);
		num >>= 1;
	}
	if (0 <= num_new && num_new <= 9) {
		return num_new + '0';
	} else {
		return num_new - 10 + 'A';
	}
}

int main(void)
{
	std::string str1, str2;
	while (std::cin >> str1 >> str2) {
		str1.append(str2);
		sort01(str1);
		for (auto &ch : str1) {
			ch = reverse01(ch);
		}
		std::cout << str1 << std::endl;
	}
	return 0;
}
