/*!
    \file      hj11.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ11 数字颠倒
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	int in;
	while (std::cin >> in) {
		while (in) {
			std::cout << in % 10;
			in /= 10;
		}
		std::cout << std::endl;
	}
	return 0;
}
