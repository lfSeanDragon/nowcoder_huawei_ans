/*!
    \file      hj70.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ70 矩阵乘法计算量估算
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>
#include <stack>

int matrix_multi(std::vector<std::pair<int, int>> &v, std::string s)
{
	int ans = 0;
	std::stack<std::pair<int, int>> stk;
	for (const auto c : s) {
		if (c == ')' && !stk.empty()) {
			auto tmp = stk.top();
			stk.pop();
			ans += stk.top().first * stk.top().second * tmp.second;
			std::pair<int, int> newp = {stk.top().first, tmp.second};
			stk.pop();
			stk.push(newp);
		} else if ('A' <= c && c <= 'Z') {
			stk.push(v[c - 'A']);
		}
	}
	return ans;
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		int first, second;
		std::string str;
		std::vector<std::pair<int, int>> vt;
		for (int i = 0; i < n; ++i) {
			std::cin >> first >> second;
			vt.push_back({first, second});
		}
		std::cin >> str;
		int res = matrix_multi(vt, str);
		std::cout << res << std::endl;
	}
	return 0;
}
