/*!
    \file      hj19.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ19 简单错误记录
    \version   1.0
    \date      2021-11-05

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main(void)
{
	std::string str;
	int count = 0;
	std::unordered_map<std::string, int>mp;
	std::vector<std::string>vt;

	while (std::getline(std::cin, str)) {
		int left = 0, right = str.size() - 1;
		while (right >= left && str[right] != ' ') {
			--right;
		}
		--right;
		left = right;
		while (left >= 0 && str[left] != '\\' && right - left + 1 <= 16) {
			--left;
		}
		++left;
		str = str.substr(left, str.size() - left);
		if (mp.find(str) != mp.end()) {
			mp[str]++;
		} else {
			mp[str] = 1;
			vt.push_back(str);
		}
	}
	int i = (vt.size() > 8) ? vt.size() - 8 : 0;
	for (const auto &x : vt) {
		if (i) {
			--i;
			continue;
		}
		std::cout << x << " " << mp[x] << std::endl;
	}
	return 0;
}
