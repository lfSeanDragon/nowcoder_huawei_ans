/*!
    \file      hj6.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ6 质数因子
    \version   1.0
    \date      2021-10-14

    \copyright Copyright (C) 2021 Archlizix

    \note      枚举到待分解数字的平方根即可，为减少浮点计算可枚举到原数的平方根。
*/

#include<iostream>

int main(void)
{
	long n, i;
	while (std::cin >> n) {
		i = 2;
		while (i * i <= n) {
			if (n % i) {
				++i;
				continue;
			}
			std::cout << i << ' ';
			n /= i;
		}
		if (n != 1) {
			std::cout << n << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}