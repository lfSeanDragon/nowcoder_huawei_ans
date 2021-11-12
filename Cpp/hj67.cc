/*!
    \file      hj67.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ67 24点游戏算法
    \version   1.0
    \date      2021-11-12

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <algorithm>
#include <vector>

bool is_valid(std::vector<int>a, int begin, int end, double tot)
{
	if (begin == end - 1) {
		return (a[begin] == tot);
	}

	bool ans = false;
	for (int i = begin; i < end; ++i) {
		std::swap(a[i], a[end - 1]);
		ans = ans ||
			  is_valid(a, begin, end - 1, tot + a[end - 1]) ||
			  is_valid(a, begin, end - 1, tot - a[end - 1]) ||
			  is_valid(a, begin, end - 1, tot * a[end - 1]) ||
			  is_valid(a, begin, end - 1, tot / a[end - 1]);
		std::swap(a[i], a[end - 1]);
	}
	return ans;
}

int main(void)
{
	std::vector<int> a(4);
	while (std::cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		if (is_valid(a, 0, 4, 24)) {
			std::cout << "true" << std::endl;
		} else {
			std::cout << "false" << std::endl;
		}
	}
}
