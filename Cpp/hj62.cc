/*!
    \file      hj62.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ62 查找输入整数二进制中1的个数
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	unsigned int n;
	while (std::cin >> n) {
		int count = 0;
		while (n) {
			n = n & (n - 1);
			++count;
		}
		std::cout << count << std::endl;
	}
	return 0;
}
