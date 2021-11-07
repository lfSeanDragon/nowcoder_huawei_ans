/*!
    \file      hj35.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ35 蛇形矩阵
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
		for (int i = 0, head = 1; i < n; ++i, head += i) {
			for (int j = 0, cur = head; j < n - i; ++j, cur += i + j + 1) {
				std::cout << cur << " ";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
