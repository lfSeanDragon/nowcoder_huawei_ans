/*!
    \file      hj58.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ58 输入n个整数，输出其中最小的k个
    \version   1.0
    \date      2021-11-11

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int n, k;
	while (std::cin >> n >> k) {
		std::vector<int> vt(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> vt[i];
		}
		sort(vt.begin(), vt.end());
		std::cout << vt[0];
		for (int i = 1; i < k; ++i) {
			std::cout << " " << vt[i];
		}
		std::cout << std::endl;
	}
	return 0;
}
