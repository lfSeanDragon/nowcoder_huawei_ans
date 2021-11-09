/*!
    \file      hj82.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ82 将真分数分解为埃及分数
    \version   1.0
    \date      2021-11-10

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	char tmp;
	int a, b;
	while (std::cin >> a >> tmp >> b) {
		while (b % a) {
			int c = b / a + 1;
			std::cout << 1 << "/" << c << "+";
			a = a - b % a;
			b = b * c;
		}
		std::cout << 1 << "/" << b / a << std::endl;
	}
	return 0;
}
