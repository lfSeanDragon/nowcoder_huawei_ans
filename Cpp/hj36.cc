/*!
    \file      hj36.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ36 字符串加密
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <unordered_set>

int main(void)
{
	std::string key, str;
	while (std::getline(std::cin, key) && std::getline(std::cin, str)) {
		std::unordered_set<char> mp;
		std::string table;

		for (int i = 0, n = key.size(); i < n; ++i) {
			char ch = tolower(key[i]);
			if (!mp.count(ch)) {
				table.push_back(ch);
				mp.insert(ch);
			}
		}

		for (char ch = 'a'; ch <= 'z'; ++ch) {
			if (!mp.count(ch))
				table = table + ch;
		}

		for (auto &ch : str) {
			if ('A' <= ch && ch <= 'Z') {
				ch = toupper(table[ch - 'A']);
			} else if ('a' <= ch && ch <= 'z') {
				ch = table[ch - 'a'];
			}
		}

		std::cout << str << std::endl;
	}
	return 0;
}
