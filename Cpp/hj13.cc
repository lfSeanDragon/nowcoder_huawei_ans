/*!
    \file      hj13.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ13 句子逆序
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note      整句读取可以用双指针扫描，逐词读取只需要简单地反转。
*/

#include<iostream>
#include<string>
#include<algorithm>

int main()
{
	std::string s;
	getline(std::cin, s);
	reverse(s.begin(), s.end());
	int left = 0, right = 0;
	while (left < s.size()) {
		while (s[left] == ' ') {
			++left;
		}
		right = left;
		while (s[right] != ' ' && s[right] != '\0') {
			++right;
		}
		reverse(s.begin() + left, s.begin() + right);
		left = right;
	}
	std::cout << s << std::endl;
	return 0;
}
