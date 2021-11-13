/*!
    \file      hj99.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ99 自守数
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>

int main(void)
{
	int n;
	while (std::cin >> n) {
		int base = 10, count = 0;
		for (int i = 0; i <= n; i++) {
			if (i == base) base *= 10;
			if (i * i % base == i) count++;
		}
		std::cout << count << std::endl;
	}
	return 0;
}
