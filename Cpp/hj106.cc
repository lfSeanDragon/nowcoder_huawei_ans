/*!
    \file      hj106.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ106 字符逆序
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <algorithm>

int main(void)
{
	std::string str;
	while (std::getline(std::cin, str)) {
		reverse(str.begin(), str.end());
		std::cout << str << std::endl;
	}
	return 0;
}
