/*!
    \file      hj28.cc
    \author    Archlizix (archlizix@qq.com)
    \brie      HJ28 素数伴侣
    \version   0.9
    \date      2021-11-08

    \copyright Copyright (C) 2021 Archlizix

    \note      dfs求01矩阵的秩，不清楚错在哪里。
*/

#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0)return false;
	}
	return true;
}

bool is_valid(std::vector<std::vector<int>> &vt, std::vector<std::vector<int>> &mask, int n)
{
	int y = n / vt.size();
	int x = n % vt.size();

	if (!vt[n / vt.size()][n % vt.size()])return false;
	for (int i = 0; i < mask.size(); ++i) {
		if (mask[i][x]) {
			return false;
		}
	}
	for (int i = 0; i < mask[0].size(); ++i) {
		if (mask[y][i]) {
			return false;
		}
	}
	return true;
}

void dfs(std::vector<std::vector<int>> &vt, std::vector<std::vector<int>> &mask, int &max, int n)
{
	if (n == vt.size()*vt[0].size()) {
		int tmp = 0;
		for (const auto &a : mask) {
			for (const auto &b : a) {
				tmp += b;
			}
		}
		max = std::max(max, tmp);
		return;
	}
	if (is_valid(vt, mask, n)) {
		mask[n / vt.size()][n % vt.size()] = 1;
		dfs(vt, mask, max, n + 1);
		mask[n / vt.size()][n % vt.size()] = 0;
	}
	dfs(vt, mask, max, n + 1);
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		int tmp;
		std::vector<int> odd, even;
		for (int i = 0; i < n; ++i) {
			std::cin >> tmp;
			if (tmp % 2) {
				odd.push_back(tmp);
			} else {
				even.push_back(tmp);
			}
		}

		std::vector<std::vector<int>>vt(odd.size(),
										std::vector<int>(even.size()));
		std::vector<std::vector<int>>mask(odd.size(),
										  std::vector<int>(even.size()));
		for (int i = 0; i < odd.size(); ++i) {
			for (int j = 0; j < even.size(); ++j) {
				if (is_prime(odd[i] + even[j]))vt[i][j] = 1;
			}
		}

		int max = 0;
		dfs(vt, mask, max, 0);
		std::cout << max << std::endl;

		//for (int i = 0; i < vt.size(); ++i) {
		//for (int j = 0; j < vt[0].size(); ++j) {
		//std::cout << vt[i][j] << " ";
		//}
		//std::cout << std::endl;
		//}
	}
	return 0;
}