/*!
    \file      hj97.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ97 记负均正
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>

int main(void)
{
	int n;
	while (std::cin >> n) {
		std::vector<int>vt(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> vt[i];
		}
		int count1 = 0;
		int sum2 = 0, count2 = 0;
		for (int i = 0; i < n; ++i) {
			if (vt[i] < 0) {
				++count1;
			} else if (vt[i] > 0) {
				sum2 += vt[i];
				++count2;
			}
		}

		std::cout << count1 << " ";
		std::cout << static_cast<int>((sum2 + 0.5) / count2) << ".";
		std::cout << (static_cast<int>(sum2 * 10.0 / count2 + 0.5)) % 10 << std::endl;
	}
	return 0;
}
