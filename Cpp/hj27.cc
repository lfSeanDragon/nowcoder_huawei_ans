/*!
    \file      hj27.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ27 查找兄弟单词
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<vector>
#include<algorithm>

bool is_valid(std::string a, std::string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		int k;
		std::vector<std::string> vt(n);
		std::string target;
		for (int i = 0; i < n; ++i) {
			std::cin >> vt[i];
		}
		std::cin >> target >> k;

		sort(vt.begin(), vt.end());

		std::string brotherk;
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (vt[i] != target && is_valid(target, vt[i])) {
				++count;
				if (count == k) brotherk = vt[i];
			}
		}

		std::cout << count << std::endl;
		if (!brotherk.empty()) std::cout << brotherk << std::endl;
	}
	return 0;
}
