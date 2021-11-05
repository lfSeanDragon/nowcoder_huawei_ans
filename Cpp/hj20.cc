/*!
    \file      hj20.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ20 密码验证合格程序
    \version   1.0
    \date      2021-11-05

    \copyright Copyright (C) 2021 Archlizix

    \note
*/
#include <iostream>
#include <string>

bool is_repeated(std::string str)
{
	int len = str.size();
	for (int i = 0; i < len - 6; ++i) {
		for (int j = i + 3; j < len - 3; ++j) {
			if (str.substr(i, 3) == str.substr(j, 3)) {
				return true;
			}
		}
	}
	return false;
}

bool is_type_rich(std::string str)
{
	int has_upper = 0, has_lower = 0, has_num = 0, has_others = 0;

	for (const auto &ch : str) {
		if ('0' <= ch && ch <= '9') {
			if (!has_num) {
				has_num = 1;
			}
		} else if ('a' <= ch && ch <= 'z') {
			if (!has_lower) {
				has_lower = 1;
			}
		} else if ('A' <= ch && ch <= 'Z') {
			if (!has_upper) {
				has_upper = 1;
			}
		} else if (ch != ' ') {
			if (!has_others) {
				has_others = 1;
			}
		}
	}

	if (has_num + has_lower + has_upper + has_others < 3) {
		return false;
	}
	return true;
}

int main(void)
{
	std::string str;
	while (std::getline(std::cin, str)) {
		if (str.size() <= 8 || !is_type_rich(str) || is_repeated(str)) {
			std::cout << "NG" << std::endl;
		} else {
			std::cout << "OK" << std::endl;
		}
	}
	return 0;
}
