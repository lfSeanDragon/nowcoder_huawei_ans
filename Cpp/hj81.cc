/*!
    \file      hj81.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ81 字符串字符匹配
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool is_valid(std::string &ss, std::string &sl)
{
	std::vector<bool> v(26, false);
	for (const auto ch : sl)
		v[ch - 'a'] = true;
	for (const auto ch : ss)
		if (!v[ch - 'a'])
			return false;
	return true;
}

int main(void)
{
	std::string ss, sl;
	while (std::cin >> ss >> sl) {
		if (is_valid(ss, sl))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	return 0;
}
