/*!
    \file      hj17.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ17 坐标移动
    \version   1.0
    \date      2021-11-04

    \copyright Copyright (C) 2021 Archlizix

    \note      switch系状态机。
*/

#include <iostream>

int x = 0, y = 0;

void move(char *op, int len)
{
	if (len != 2 && len != 3) {
		return;
	}
	if (op[1] < '0' || op[1] > '9') {
		return;
	}
	if (len == 3 && (op[2] < '0' || op[2] > '9')) {
		return;
	}

	int num = op[1] - '0';
	if (len == 3) {
		num = num * 10 + (op[2] - '0');
	}

	switch (op[0]) {
	case 'A':
		x -= num;
		break;
	case 'S':
		y -= num;
		break;
	case 'D':
		x += num;
		break;
	case 'W':
		y += num;
		break;
	default:
		break;
	}
}

int main(void)
{
	char ch;
	char op[3];
	int p = 0;
	while (1) {
		ch = getchar();
		switch (ch) {
		case ';':
			move(op, p);
			p = 0;
			break;
		case '\n':
			move(op, p);
			std::cout << x << "," << y << std::endl;
			x = 0;
			y = 0;
			p = 0;
			break;
		case EOF:
			move(op, p);
			if (x || y) {
				std::cout << x << "," << y << std::endl;
			}
			return 0;
		default:
			if (p < 3) {
				op[p] = ch;
			}
			p++;
			break;
		}
	}

	return 0;
}
