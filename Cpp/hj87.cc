/*!
    \file      hj87.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ87 密码强度等级
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
		int n = str.size(), n_upper = 0, n_lower = 0, n_num = 0, n_symbol = 0;
		for (const auto &ch : str) {
			if (islower(ch)) {
				++n_lower;
			} else if (isupper(ch)) {
				++n_upper;
			} else if (isdigit(ch)) {
				++n_num;
			} else {
				++n_symbol;
			}
		}

		int scope = 0;
		if (n <= 4) {
			scope += 5;
		} else if (n >= 8) {
			scope += 25;
		} else {
			scope += 10;
		}

		if ((!n_lower && n_upper) || (n_lower && !n_upper)) {
			scope += 10;
		} else if (n_lower * n_upper) {
			scope += 20;
		}

		if (n_num > 1) {
			scope += 20;
		} else if (n_num) {
			scope += 10;
		}

		if (n_symbol > 1) {
			scope += 25;
		} else if (n_symbol) {
			scope += 10;
		}

		if (n_upper && n_lower && n_num && n_symbol) {
			scope += 5;
		} else if ((n_upper + n_lower) && n_num && n_symbol) {
			scope += 3;
		} else if ((n_upper + n_lower) && n_num) {
			scope += 2;
		}

		if (scope >= 90) {
			std::cout << "VERY_SECURE" << std::endl;
		} else if (scope >= 80) {
			std::cout << "SECURE" << std::endl;
		} else if (scope >= 70) {
			std::cout << "VERY_STRONG" << std::endl;
		} else if (scope >= 60) {
			std::cout << "STRONG" << std::endl;
		} else if (scope >= 50) {
			std::cout << "AVERAGE" << std::endl;
		} else if (scope >= 25) {
			std::cout << "WEAK" << std::endl;
		} else {
			std::cout << "VERY_WEAK" << std::endl;
		}
	}
	return 0;
}
