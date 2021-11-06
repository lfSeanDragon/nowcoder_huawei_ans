/*!
    \file      hj76.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ76 尼科彻斯定理
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	int m;
	while (std::cin >> m) {
		int n = m * m * m;
		for (int i = 1; i < n; ++i) {
			if (n == i * m + m * m - m) {
				std::cout << i;
				for (int j = 1; j < m; ++j) {
					std::cout << "+" << i + j * 2;
				}
				std::cout << std::endl;
				break;
			}
		}
	}
	return 0;
}
