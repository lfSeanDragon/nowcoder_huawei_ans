/*!
    \file      hj45.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ45 名字的漂亮度
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main(void)
{
	int n;
	while (std::cin >> n) {
		for (int i = 0; i < n; ++i) {
			std::string str;
			std::cin >> str;
			std::vector<int> dp(27, 0);
			for (const auto &ch : str) {
				++dp[tolower(ch) - 'a' + 1];
			}
			int flag = 1;
			while (flag) {
				flag = 0;
				for (int i = 1; i < 27; ++i) {
					if (dp[i] > dp[i - 1]) {
						std::swap(dp[i], dp[i - 1]);
						flag = 1;
					}
				}
			}
			int sum = 0, tmp = 26;
			for (int i = 0; i < 27; ++i) {
				sum = sum + (tmp--) * dp[i];
			}
			std::cout << sum << std::endl;
		}
	}
	return 0;
}
