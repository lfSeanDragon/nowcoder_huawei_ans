/*!
    \file      hj38.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ38 求小球落地5次后所经历的路程和第5次反弹的高度
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
		std::cout << n * 2.875 << std::endl;
		std::cout << n / 32.0 << std::endl;
	}
	return 0;
}
