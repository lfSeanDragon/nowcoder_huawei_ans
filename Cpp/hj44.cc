#include<iostream>

int num[9][9];
bool flag = false;

bool check(int n, int key)
{
	for (int i = 0; i < 9; ++i) {
		int j = n / 9;
		if (num[j][i] == key) return false;
	}
	for (int i = 0; i < 9; ++i) {
		int j = n % 9;
		if (num[i][j] == key) return false;
	}
	int x = n / 9 / 3 * 3;
	int y = n % 9 / 3 * 3;
	for (int i = x; i < x + 3; ++i)
		for (int j = y; j < y + 3; ++j)
			if (num[i][j] == key) return false;
	return true;
}

void dfs(int n)
{
	if (n == 81) {
		flag = true;
		return ;
	}
	if (num[n / 9][n % 9] != 0) dfs(n + 1);
	else {
		for (int i = 1; i <= 9; ++i) {
			if (check(n, i)) {
				num[n / 9][n % 9] = i;
				dfs(n + 1);
				if (flag) return ;
				num[n / 9][n % 9] = 0;
			}
		}
	}
	return ;
}

int main(void)
{
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			std::cin >> num[i][j];
		}
	}
	dfs(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << num[i][j] << " ";
		}
		std::cout << num[i][8] << std::endl;
	}
	return 0;
}
