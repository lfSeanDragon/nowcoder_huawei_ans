/*!
    \file      hj43.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ43 迷宫问题
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>

int n, m;
std::vector<std::vector<int>> maze;
std::vector<std::vector<int>> path_temp;
std::vector<std::vector<int>> path_best;

void dfs(int i, int j)
{
	maze[i][j] = 1;
	path_temp.push_back({ i, j });
	if (i == n - 1 && j == m - 1)
		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;
	if (i - 1 >= 0 && maze[i - 1][j] == 0)
		dfs(i - 1, j);
	if (i + 1 < n && maze[i + 1][j] == 0)
		dfs(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)
		dfs(i, j - 1);
	if (j + 1 < m && maze[i][j + 1] == 0)
		dfs(i, j + 1);
	maze[i][j] = 0;
	path_temp.pop_back();
}

int main(void)
{
	while (std::cin >> n >> m) {
		maze = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
			for (auto &j : i)
				std::cin >> j;
		dfs(0, 0);
		for (const auto i : path_best)
			std::cout << '(' << i[0] << ',' << i[1] << ')' << std::endl;
	}
	return 0;
}
