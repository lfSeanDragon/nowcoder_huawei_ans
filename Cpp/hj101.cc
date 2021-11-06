/*!
    \file      hj101.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ101 输入整型数组和排序标识，对其元素按照升序或降序进行排序
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int n;
	std::vector<int>num;
	int order;

	while (std::cin >> n) {
		num.resize(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> num[i];
		}
		std::cin >> order;

		sort(num.begin(), num.end());
		if (order) {
			reverse(num.begin(), num.end());
		}

		for (const auto &x : num) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
