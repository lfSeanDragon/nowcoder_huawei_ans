/*!
    \file      hj53.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ53 杨辉三角的变形
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>

int main(void)
{
	int num;
	while (std::cin >> num) {
		if (num == 0 || num == 1 || num == 2)std::cout << -1 << std::endl;
		else if (num % 4 == 0)std::cout << 3 << std::endl;
		else if (num % 4 == 1)std::cout << 2 << std::endl;
		else if (num % 4 == 2)std::cout << 4 << std::endl;
		else std::cout << 2 << std::endl;
	}
	return 0;
}
