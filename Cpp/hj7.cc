/*!
    \file      hj7.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ7 取近似值
    \version   2.0
    \date      2021-10-14

    \copyright Copyright (C) 2021 Archlizix

    \note      正数与负数舍入方向不同。
*/

#include<iostream>

int main()
{
	double a;
	int b;

	while (std::cin >> a) {
		b = static_cast<int>(a);
		if (a - b >= 0.5) {
			std::cout <<  b + 1 << std::endl;
		} else if (a - b <= -0.5) {
			std::cout << b - 1 << std::endl;
		} else {
			std::cout << b << std::endl;
		}
	}

	return 0;
}