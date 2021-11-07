/*!
    \file      hj59.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ59 找出字符串中第一个只出现一次的字符
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
		int count[26] = {0};
		for (int i = 0, n = str.size(); i < n; ++i) {
			++count[str[i] - 'a'];
		}

		int i;
		for (i = 0; i < str.size(); ++i) {
			if (count[str[i] - 'a'] == 1) {
				std::cout << str[i] << std::endl;
				break;
			}
		}
		if (i == str.size()) std::cout << -1 << std::endl;
	}
	return 0;
}
