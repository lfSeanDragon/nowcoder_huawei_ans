/*!
    \file      hj86.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ86 求最大连续bit数
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>

int main(void)
{
	int n;
	while (std::cin >> n) {
		int i = 0;
		while (n) {
			n = n & (n << 1);
			++i;
		}
		std::cout << i << std::endl;
	}
	return 0;
}
