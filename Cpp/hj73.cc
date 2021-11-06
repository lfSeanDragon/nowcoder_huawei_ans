/*!
    \file      hj73.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ73 计算日期到天数转换
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	int y, m, d;
	while (std::cin >> y >> m >> d) {
		int total = d;
		switch (m) {
		case 12: total += 30;
		case 11: total += 31;
		case 10: total += 30;
		case 9: total += 31;
		case 8: total += 31;
		case 7: total += 30;
		case 6: total += 31;
		case 5: total += 30;
		case 4: total += 31;
		case 3:
			if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0) {
				total += 29;
			} else {
				total += 28;
			}
		case 2: total += 31;
		default: break;
		}
		std::cout << total << std::endl;
	}
	return 0;
}
