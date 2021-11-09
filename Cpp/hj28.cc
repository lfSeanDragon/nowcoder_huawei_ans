/*!
    \file      hj28.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ28 素数伴侣
    \version   1.0
    \date      2021-11-09

    \copyright Copyright (C) 2021 Archlizix

    \note      匈牙利算法求二分图的最大匹配。
*/

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> even, odd;
std::vector<int>match(100), book(100);

bool is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0)return false;
	}
	return true;
}

bool dfs(int evenx)
{
	for (int i = 0; i < odd.size(); ++i) {
		if (book[i] == 0 && is_prime(even[evenx] + odd[i])) {
			book[i] = 1;
			if (match[i] == -1 || dfs(match[i])) {
				match[i] = evenx;
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		int tmp;
		for (int i = 0; i < n; ++i) {
			std::cin >> tmp;
			if (tmp % 2) {
				even.push_back(tmp);
			} else {
				odd.push_back(tmp);
			}
		}
		for (int i = 0; i < n; ++i) match[i] = -1;

		int max = 0;
		for (int i = 0; i < even.size(); ++i) {
			for (int j = 0; j < odd.size(); ++j) book[j] = 0;
			if (dfs(i)) ++max;
		}

		std::cout << max << std::endl;
		even.clear();
		odd.clear();
	}
	return 0;
}
