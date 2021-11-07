/*!
    \file      hj60.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ60 查找组成一个偶数最接近的两个素数
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <cmath>

bool is_valid(int n)
{
	for (int i = 2; i <= std::sqrt(n); ++i) {
		if (n % i == 0)return false;
	}
	return true;
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		int flag = 0;
		for (int i = n / 2; i >= 2 && !flag; --i) {
			if (!is_valid(i))continue;
			for (int j = n / 2; j < n && !flag; ++j) {
				if (!is_valid(j))continue;
				if (i + j == n) {
					std::cout << i << std::endl;
					std::cout << j << std::endl;
					flag = 1;
				}
			}
		}
	}
	return 0;
}
