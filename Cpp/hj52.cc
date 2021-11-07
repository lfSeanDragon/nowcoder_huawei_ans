/*!
    \file      hj52.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ52 计算字符串的距离
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <vector>

int levenshtein_distance(std::string &a, std::string &b)
{
	int n = a.size(), m = b.size();
	std::vector<std::vector<int>>dp(n + 1, std::vector<int>(m + 1, 0));
	dp[0][0] = 0; //a前x字符子串与b前y字符子串的距离
	for (int i = 1; i <= m; ++i) dp[0][i] = i;
	for (int i = 1; i <= n; ++i) dp[i][0] = i;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int case1 = dp[i - 1][j] + 1;
			int case2 = dp[i][j - 1] + 1;
			int case3 = dp[i - 1][j - 1];
			if (a[i - 1] != b[j - 1]) ++case3;
			dp[i][j] = std::min(std::min(case1, case2), case3);
		}
	}
	return dp[n][m];
}

int main(void)
{
	std::string a, b;
	while (std::cin >> a >> b) {
		std::cout << levenshtein_distance(a, b) << std::endl;
	}
	return 0;
}
