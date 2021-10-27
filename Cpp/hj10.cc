/*!
    \file      hj10.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ10 字符个数统计
    \version   1.0
    \date      2021-10-27

    \copyright Copyright (C) 2021 Archlizix

    \note      128 bytes, such a big deal.
*/

#include <iostream>
#include <string>
#include <unordered_set>

int main(void)
{
	std::string s;
	std::unordered_set<char>st;

	while (std::cin >> s) {
		for (const auto &ch : s) {
			st.emplace(ch);
		}

		std::cout << st.size() << std::endl;
	}

	return 0;
}
