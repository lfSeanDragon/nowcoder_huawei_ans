/*!
    \file      hj40.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ40 统计字符
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
		int n_alpha = 0, n_space = 0, n_digit = 0, n_others = 0;
		for (const auto &ch : str) {
			if (isalpha(ch)) {
				++n_alpha;
			} else if (isdigit(ch)) {
				++n_digit;
			} else if (isspace(ch)) {
				++n_space;
			} else {
				++n_others;
			}
		}
		std::cout << n_alpha << std::endl
				  << n_space << std::endl
				  << n_digit << std::endl
				  << n_others << std::endl;
	}
	return 0;
}
