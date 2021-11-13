/*!
    \file      hj92.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ92 在字符串中找出连续最长的数字串
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	while (std::cin >> str) {
		std::string s = "";
		std::string res = "";
		int len = 0;
		int maxl = 0;
		for (int i = 0; i < str.length(); ++i) {
			if (isdigit(str[i])) {
				++len;
				s += str[i];
				if (i + 1 < str.length())
					continue;
			}
			if (len > maxl) {
				res = s;
				maxl = len;
			} else if (len == maxl) {
				res += s;
			}
			len = 0 ;
			s.clear();
		}
		std::cout << res << "," << maxl << std::endl;;
	}
	return 0;
}
