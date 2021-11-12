/*!
    \file      hj69.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ69 矩阵乘法
    \version   1.0
    \date      2021-11-12

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<vector>

int main(void)
{
	int x, y, z;
	while (std::cin >> x >> y >> z) {
		std::vector<std::vector<int>> arr1(x, std::vector<int>(y, 0));
		std::vector<std::vector<int>> arr2(y, std::vector<int>(z, 0));
		std::vector<std::vector<int>> arr3(x, std::vector<int>(z, 0));
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j)
				std::cin >> arr1[i][j];
		}
		for (int i = 0; i < y; ++i) {
			for (int j = 0; j < z; ++j)
				std::cin >> arr2[i][j];
		}
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j)
				for (int k = 0; k < z; ++k)
					arr3[i][k] += arr1[i][j] * arr2[j][k];
		}
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < z - 1; ++j)
				std::cout << arr3[i][j] << " ";
			std::cout << arr3[i][z - 1] << std::endl;
		}
	}
	return 0;
}
