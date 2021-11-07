/*!
    \file      hj57.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ57 高精度整数加法
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <algorithm>

int main(void)
{
	std::string s1, s2;
	while (std::cin >> s1 >> s2) {
		std::reverse(s1.begin(), s1.end());
		std::reverse(s2.begin(), s2.end());
		while (s1.size() < s2.size()) {
			s1.push_back('0');
		}
		while (s2.size() < s1.size()) {
			s2.push_back('0');
		}
		std::string ans;
		int inc = 0;
		for (int i = 0, n = s1.size(); i < n; ++i) {
			int tmp = s1[i] + s2[i] - 2 * '0' + inc;
			ans.push_back(tmp % 10 + '0');
			inc = tmp / 10;
		}
		if (inc)ans.push_back(inc + '0');
		std::reverse(ans.begin(), ans.end());
		std::cout << ans << std::endl;
	}
	return 0;
}
