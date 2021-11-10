/*!
    \file      hj33.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ33 整数与IP地址间的转换
    \version   1.0
    \date      2021-11-10

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <cstdint>

int main(void)
{
	uint32_t n, a, b, c, d;
	char ch;
	while (std::cin >> a >> ch >> b >> ch >> c >> ch >> d) {
		std::cin >> n;
		uint32_t res = (a << 24)  + (b << 16) + (c << 8)  + d;
		a = n >> 24;
		b = (n >> 16) & 0xFF;
		c = (n >> 8) & 0xFF;
		d = n & 0xFF;
		std::cout << res << std::endl << a << '.' << b << '.' << c << '.' << d << std::endl;
	}
	return 0;
}
