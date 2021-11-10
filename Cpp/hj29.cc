/*!
    \file      hj29.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ29 字符串加解密
    \version   1.0
    \date      2021-11-10

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

char encrypt(char ch)
{
	if (isdigit(ch)) {
		ch = (ch - '0' + 1) % 10 + '0';
	} else if (isupper(ch)) {
		ch = (ch - 'A' + 1) % 26 + 'a';
	} else {
		ch = (ch - 'a' + 1) % 26 + 'A';
	}
	return ch;
}

char decode(char ch)
{
	if (isdigit(ch)) {
		ch = (ch - '0' - 1 + 10) % 10 + '0';
	} else if (isupper(ch)) {
		ch = (ch - 'A' - 1 + 26) % 26 + 'a';
	} else {
		ch = (ch - 'a' - 1 + 26) % 26 + 'A';
	}
	return ch;
}

int main(void)
{
	std::string str1, str2;
	while (std::cin >> str1 >> str2) {
		for (auto &ch : str1) {
			ch = encrypt(ch);
		}
		for (auto &ch : str2) {
			ch = decode(ch);
		}
		std::cout << str1 << std::endl;
		std::cout << str2 << std::endl;
	}
	return 0;
}
