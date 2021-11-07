/*!
    \file      hj100.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ100 等差数列
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	int n;
	while (std::cin >> n) {
		std::cout << (3 * n * n + n) / 2 << std::endl;
	}
	return 0;
}
