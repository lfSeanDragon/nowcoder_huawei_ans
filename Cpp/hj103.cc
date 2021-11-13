/*!
    \file      hj103.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ103 Redraiment的走法
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int n;
	while (std::cin >> n) {
		std::vector <int> v(n);
		for (int i = 0; i < n; i++)
			std::cin >> v[i];

		std::vector<int>dp(v.size(), 1);
		int result = 0;
		for (int i = 1; i < v.size(); i++) {
			for (int j = 0; j < i; j++)
				if (v[i] > v[j]) dp[i] = std::max(dp[i], dp[j] + 1);
			if (dp[i] > result)
				result = dp[i];
		}

		std::cout << result << std::endl;
	}
	return 0;
}
