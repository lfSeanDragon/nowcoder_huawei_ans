/*!
    \file      hj24.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ24 合唱队
    \version   1.0
    \date      2021-11-05

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<vector>
#include<algorithm>

int main(void)
{
	int n;
	while (std::cin >> n) {
		std::vector<int> height(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> height[i];
		}

		std::vector<int> dp1(n);
		std::vector<int> dp2(n);
		for (int i = 0; i < n; ++i) {
			dp1[i] = 1;
			for (int j = 0; j < i; ++j) {
				if (height[i] > height[j]) {
					dp1[i] = std::max(dp1[i], dp1[j] + 1);
				}
			}
		}
		for (int i = n - 1; i >= 0; --i) {
			dp2[i] = 1;
			for (int j = n - 1; j > i; --j) {
				if (height[i] > height[j]) {
					dp2[i] = std::max(dp2[i], dp2[j] + 1);
				}
			}
		}

		int max = 0;
		for (int i = 0; i < n; ++i) {
			if (dp1[i] + dp2[i] - 1 > max) {
				max = dp1[i] + dp2[i] - 1;
			}
		}
		std::cout << n - max << std::endl;
	}
	return 0;
}
