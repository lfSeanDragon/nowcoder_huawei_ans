/*!
    \file      hj91.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ91 走方格的方案数
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

void dfs(int n, int m, int x, int y, int &count)
{
	if (x > n || y > m) {
		return;
	}
	if (x == n && y == m) {
		++count;
		return;
	}
	dfs(n, m, x + 1, y, count);
	dfs(n, m, x, y + 1, count);
}

int main(void)
{
	int m, n;
	while (std::cin >> n >> m) {
		int count = 0;
		dfs(n, m, 0, 0, count);
		std::cout << count << std::endl;
	}
	return 0;
}
