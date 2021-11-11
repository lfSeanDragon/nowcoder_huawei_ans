/*!
    \file      hj25.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ25 数据分类处理
    \version   1.0
    \date      2021-11-11

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <set>
#include <string>

bool is_valid(uint32_t a, uint32_t b)
{
	std::string aa = std::to_string(a);
	std::string bb = std::to_string(b);
	int pos = aa.find(bb);
	if (pos != std::string::npos)
		return true;
	else
		return false;
}

int main(void)
{
	uint32_t n, m;
	while (std::cin >> n) {
		std::vector<uint32_t> I(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> I[i];
		}
		std::set<uint32_t> R;
		std::cin >> m;
		for (int i = 0; i < m; ++i) {
			uint32_t tmp;
			std::cin >> tmp;
			R.emplace(tmp);
		}
		std::vector<uint32_t> ans;
		for (const auto x : R) {
			std::vector<uint32_t> ans_tmp;
			for (int i = n - 1; i >= 0; --i) {
				if (is_valid(I[i], x)) {
					ans_tmp.push_back(I[i]);
					ans_tmp.push_back(i);
				}
			}
			if (!ans_tmp.empty()) {
				ans.push_back(x);
				ans.push_back(ans_tmp.size() / 2);
				while (!ans_tmp.empty()) {
					ans.push_back(ans_tmp.back());
					ans_tmp.pop_back();
				}
			}
		}

		std::cout << ans.size();
		for (const auto x : ans) {
			std::cout << " " << x;
		}
		std::cout << std::endl;
	}
	return 0;
}
