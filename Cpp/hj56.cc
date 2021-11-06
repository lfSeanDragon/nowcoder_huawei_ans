/*!
    \file      hj56.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ56 完全数计算
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

bool is_valid(int n)
{
	int sum = 0;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0)sum += i;
	}
	return sum == n;
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		if (n < 6) {
			std::cout << 0 << std::endl;
			continue;
		}
		int ans = 0;
		for (int i = 6; i <= n; ++i) {
			if (is_valid(i)) {
				++ans;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
