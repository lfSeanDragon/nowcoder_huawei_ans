/*!
    \file      hj12.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ12 字符串反转
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<string>

int main(void)
{
	std::string s;
	while (std::cin >> s) {
		for (int i = s.size() - 1; i >= 0; --i) {
			std::cout << s[i] ;
		}
		std::cout << std::endl;
	}
	return 0;
}
