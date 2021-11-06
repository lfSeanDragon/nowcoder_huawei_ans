/*!
    \file      hj31.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ31 单词倒排
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

auto is_letter(const char &ch)
{
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

void split_str(std::string &str, std::vector<std::string> &vt)
{
	vt.clear();
	int len = str.size();
	if (!len) {
		return;
	}
	int left = 0, right = 0;
	while (left < len && right < len) {
		while (left < len && !is_letter(str[left])) {
			++left;
		}
		if (left == len) {
			break;
		}
		right = left;
		while (right < len && is_letter(str[right])) {
			++right;
		}
		vt.push_back(str.substr(left, right - left));
		left = right;
	}
	return;
}

int main(void)
{
	std::string str;
	while (std::getline(std::cin, str)) {
		std::vector<std::string> vt;
		split_str(str, vt);
		reverse(vt.begin(), vt.end());
		for (const auto &x : vt) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
