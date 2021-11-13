/*!
    \file      hj105.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ105 记负均正II
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <iomanip>

int main(void)
{
	int tmp;
	int counta = 0, countb = 0, suma = 0;
	while (std::cin >> tmp) {
		if (tmp < 0) {
			countb++;
		} else {
			counta++;
			suma += tmp;
		}
	}
	std::cout << countb << std::endl;
	if (counta > 0)
		std::cout << std::fixed << std::setprecision(1) <<
				  suma * 1.0 / counta << std::endl;
	else
		std::cout << "0.0" << std::endl;
	return 0;
}
