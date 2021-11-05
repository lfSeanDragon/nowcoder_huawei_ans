/*!
    \file      hj23.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ23 删除字符串中出现次数最少的字符
    \version   1.0
    \date      2021-11-05

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	while (std::cin >> str) {
		int scope[26] = {0};
		for (const auto &ch : str) {
			++scope[ch - 'a'];
		}
		int least = 20;
		for (const auto &ch : str) {
			if (scope[ch - 'a'] < least) {
				least = scope[ch - 'a'];
			}
		}
		for (const auto &ch : str) {
			if (scope[ch - 'a'] != least) {
				std::cout << ch;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
