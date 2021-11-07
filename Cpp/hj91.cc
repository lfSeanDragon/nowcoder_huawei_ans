/*!
    \file      hj91.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ91 走方格的方案数
    \version   2.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note      动态规划法，另可用深度搜索法和排列组合法。注意走边沿线比走格子横纵各多一步。
*/

#include <iostream>
#include <vector>

int main(void)
{
	int n, m;
	while (std::cin >> n >> m) {
		std::vector<std::vector<int>> vt(n + 1, std::vector<int>(m + 1, 1));

		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < m + 1; ++j) {
				vt[i][j] = vt[i - 1][j] + vt[i][j - 1];
			}
		}

		std::cout << vt[n][m] << std::endl;
	}
	return 0;
}
