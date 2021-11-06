/*!
    \file      hj75.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ75 公共子串计算
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

int main(void)
{
	std::string s1, s2;
	while (std::cin >> s1 >> s2) {
		int max = 0;
		for (int i = 0, len1 = s1.size(); i < len1; ++i) {
			for (int j = 0, len2 = s2.size(); j < len2; ++j)
				if (s1[i] == s2[j]) {
					int n = 0;
					while (s1[i + n] == s2[j + n] && n + i < len1 && j + n < len2) {
						++n;
					}
					if (n > max) {
						max = n;
					}
				}
		}
		std::cout << max << std::endl;
	}
	return 0;
}
