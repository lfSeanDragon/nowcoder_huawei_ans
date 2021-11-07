/*!
    \file      hj34.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ34 图片整理
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <algorithm>
#include <string>

int main(void)
{
	std::string str;
	while (std::cin >> str) {
		std::sort(str.begin(), str.end());
		std::cout << str << std::endl;
	}
	return 0;
}
