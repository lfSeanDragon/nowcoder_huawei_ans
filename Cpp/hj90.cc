/*!
    \file      hj90.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ90 合法IP
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	int a, b, c, d;
	char ch;
	while (std::cin >> a >> ch >> b >> ch >> c >> ch >> d) {
		if (a < 0 || b < 0 || c < 0 || d < 0 ||
			a > 255 || b > 255 || c > 255 || d > 255)
			std::cout << "NO" << std::endl;
		else
			std::cout << "YES" << std::endl;
	}
	return 0;
}
