/*!
    \file      hj46.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ46 截取字符串
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
	int k;
	while (std::cin >> str >> k) {
		std::cout << str.substr(0, k) << std::endl;
	}
	return 0;
}
