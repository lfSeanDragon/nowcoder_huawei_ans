/*!
    \file      hj96.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ96 表示数字
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

int main(void)
{
	std::string s;
	while (std::cin >> s) {
		std::string res;
		for (int i = 0; i < s.length(); i++) {
			if (isdigit(s[i]) &&
				(i == 0 || !isdigit(s[i - 1])))
				res.push_back('*');

			res.push_back(s[i]);

			if (isdigit(s[i]) &&
				(i + 1 == s.length() || !isdigit(s[i + 1])))
				res.push_back('*');
		}
		std::cout << res << std::endl;
	}
	return 0;
}
