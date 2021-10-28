/*!
    \file      hj16.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ16 购物单
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note      动态规划，机械枚举4种情况。
*/

#include <iostream>
#include <algorithm>

int main(void)
{
	int N, m;
	while (std::cin >> N >> m) {
		int price[61][3] = {0};
		int weight[61][3] = {0};

		for (int i = 1; i <= m; i++) {
			int v, p, q;
			std::cin >> v >> p >> q;
			if (q) { //表示附件
				if (!price[q][1]) { //表示第一件附件
					price[q][1] = v;
					weight[q][1] = v * p;
				} else {
					price[q][2] = v;
					weight[q][2] = v * p;
				}
			} else {
				price[i][0] = v;
				weight[i][0] = v * p;
			}
		}

		int n = N / 10;
		int total_max[3200] = {0};
		for (int i = 1; i <= m; ++i) {
			for (int j = n; j >= price[i][0] / 10; --j) {
				int price_total, weight_total;

				total_max[j] = std::max(total_max[j],
										total_max[j - price[i][0] / 10] + weight[i][0]); //不带附件

				price_total = price[i][0] / 10 + price[i][1] / 10;
				weight_total = weight[i][0] + weight[i][1];
				if (price_total <= j && price[i][1]) { //带附件1
					total_max[j] = std::max(total_max[j], total_max[j - price_total] + weight_total);
				}

				price_total = price[i][0] / 10 + price[i][2] / 10;
				weight_total = weight[i][0] + weight[i][2];
				if (price[i][2] && j >= price_total) { //带附件1
					total_max[j] = std::max(total_max[j], total_max[j - price_total] + weight_total);
				}

				price_total = price[i][0] / 10 + price[i][2] / 10 + price[i][1] / 10;
				weight_total = weight[i][0] + weight[i][2] + weight[i][1];
				if (price[i][1] && price[i][2] && j >= price_total) { //带附件1、2
					total_max[j] = std::max(total_max[j], total_max[j - price_total] + weight_total);
				}
			}
		}

		std::cout << total_max[n] << std::endl;
	}
	return 0;
}
