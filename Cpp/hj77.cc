#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>

int n;
std::vector<int> id;
std::stack<int> train;
std::vector<std::string> order;

void dfs(int num, std::string str)
{
	if (num == 0 && train.empty()) {
		order.push_back(str);
		return;
	}
	if (num > 0) {
		train.push(id[n - num]);
		dfs(num - 1, str);
		train.pop();
	}
	if (!train.empty()) {
		int temp = train.top();
		train.pop();
		dfs(num, str + char('0' + temp) + ' ');
		train.push(temp);
	}
}

int main(void)
{
	while (std::cin >> n) {
		id.resize(n);
		order.clear();
		for (int i = 0; i < n; ++i)
			std::cin >> id[i];
		dfs(n, "");
		sort(order.begin(), order.end());
		for (int i = 0; i < order.size(); i++)
			std::cout << order[i] << std::endl;
	}
	return 0;
}
