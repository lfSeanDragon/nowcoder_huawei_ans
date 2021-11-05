/*!
    \file      hj21.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ21 简单密码
    \version   1.0
    \date      2021-11-05

    \copyright Copyright (C) 2021 Archlizix

    \note
*/
#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	while (std::getline(std::cin, str)) {
		for (const auto &ch : str) {
			if ('A' <= ch && ch <= 'Z') {
				std::cout << (char)(((ch - 'A' + 1) % ('z' - 'a' + 1)) + 'a');
			} else if ('a' <= ch && ch <= 'z') {
				switch (ch) {
				case 'a':
				case 'b':
				case 'c':
					std::cout << 2;
					break;
				case 'd':
				case 'e':
				case 'f':
					std::cout << 3;
					break;
				case 'g':
				case 'h':
				case 'i':
					std::cout << 4;
					break;
				case 'j':
				case 'k':
				case 'l':
					std::cout << 5;
					break;
				case 'm':
				case 'n':
				case 'o':
					std::cout << 6;
					break;
				case 'p':
				case 'q':
				case 'r':
				case 's':
					std::cout << 7;
					break;
				case 't':
				case 'u':
				case 'v':
					std::cout << 8;
					break;
				case 'w':
				case 'x':
				case 'y':
				case 'z':
					std::cout << 9;
					break;
				default:
					break;
				}
			} else {
				std::cout << ch;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
