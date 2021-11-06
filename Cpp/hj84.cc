/*!
    \file      hj84.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ84 统计大写字母个数
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	while (std::getline(std::cin, str)) {
		int n = 0;
		for (const auto &ch : str) {
			if (isupper(ch))++n;
		}
		std::cout << n << std::endl;
	}
	return 0;
}
