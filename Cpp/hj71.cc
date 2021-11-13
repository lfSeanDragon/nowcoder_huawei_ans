/*!
    \file      hj71.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ71 字符串通配符
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<vector>
#include<string>

bool is_valid(char ch)
{
	if (isalpha(ch) || isdigit(ch))
		return true;
	else
		return false;
}

bool is_match(const std::string &pattern, const std::string &str)
{
	int n = pattern.length();
	int m = str.length();
	std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; ++i)
		dp[i][0] = dp[i - 1][0] && (pattern[i - 1] == '*');

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char ch1 = pattern[i - 1];
			char ch2 = str[j - 1];
			if (ch1 == '*')
				dp[i][j] = (dp[i][j - 1] && is_valid(ch2)) ||
						   (dp[i - 1][j - 1] && is_valid(ch2)) ||
						   dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j - 1] && (ch1 == ch2 || (ch1 == '?' && is_valid(ch2)));
		}
	return dp[n][m];
}

int main(void)
{
	std::string str1, str2;
	while (std::cin >> str1 >> str2) {
		for (auto &ch : str1)
			ch = tolower(ch);
		for (auto &ch : str2)
			ch = tolower(ch);

		if (is_match(str1, str2))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	return 0;
}
