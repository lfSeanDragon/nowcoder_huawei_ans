/*!
    \file      hj108.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ108 求最小公倍数
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <utility>

int main(void)
{
	int a, b;
	while (std::cin >> a >> b) {
		if (a < b) std::swap(a, b);
		for (int i = 1; i <= b; ++i) {
			if (a * i % a == 0 && a * i % b == 0) {
				std::cout << a *i << std::endl;
				break;
			}
		}
	}
	return 0;
}
