/*!
    \file      hj83.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ83 二维数组操作
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>

int main(void)
{
	int m, n;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	while (std::cin >> m >> n >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
		if (m <= 9 && n <= 9) std::cout << 0 << std::endl;
		else {
			std::cout << -1 << std::endl;
			m = n = 9;
		}

		if (x1 < m && y1 < n && x2 < m && y2 < n) std::cout << 0 << std::endl;
		else std::cout << -1 << std::endl;

		if (x3 < m && m < 9) std::cout << 0 << std::endl;
		else std::cout << -1 << std::endl;

		if (y3 < n && n < 9) std::cout << 0 << std::endl;
		else std::cout << -1 << std::endl;

		if (x4 < m && y4 < n) std::cout << 0 << std::endl;
		else std::cout << -1 << std::endl;
	}
}
