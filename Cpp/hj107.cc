/*!
    \file      hj107.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ107 求解立方根
    \version   1.0
    \date      2021-11-11

    \copyright Copyright (C) 2021 Archlizix

    \note      二分法
*/

#include <iostream>
#include <climits>
#include <cstdint>

double cuberoot(double x)
{
	double left = INT_MIN, right = INT_MAX, mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		double temp = mid * mid * mid;
		if (temp > x) {
			right = mid - 0.01;
		} else if (temp < x) {
			left = mid + 0.01;
		} else return mid;
	}
	return left;
}

int main(void)
{
	double n;
	while (std::cin >> n) {
		std::cout << cuberoot(n) << std::endl;
	}
	return 0;
}
