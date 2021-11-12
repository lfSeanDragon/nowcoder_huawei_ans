/*!
    \file      hj65.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ65 查找两个字符串a,b中的最长公共子串
    \version   1.0
    \date      2021-11-12

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <algorithm>
#include <string>

int main(void)
{
	std::string str1, str2;
	while (std::cin >> str1 >> str2) {
		int n1 = str1.size(), n2 = str2.size();
		if (n1 > n2) {
			std::swap(n1, n2);
			std::swap(str1, str2);
		}
		int mi = 0, ms = 0;
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < n2; ++j) {
				int tmp = 0;
				while (str1[i + tmp] == str2[j + tmp] &&
					   i + tmp < n1 && j + tmp < n2) {
					++tmp;
				}
				if (tmp > ms) {
					ms = tmp;
					mi = i;
				}
			}
		}

		for (int i = 0; i < ms; ++i) {
			std::cout << str1[mi + i];
		}
		std::cout << std::endl;
	}
}
