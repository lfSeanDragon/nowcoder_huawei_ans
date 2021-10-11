#include<iostream>
#include<string>

int main(void)
{
	constexpr int max_str_size = 500;
	char str[max_str_size];
	char ch;
	int num = 0;

	std::cin.getline(str, max_str_size);
	std::cin >> ch;
	if ('A' <= ch && ch <= 'Z') {
		ch += 32;
	}

	for (int i = 0; str[i] != '\0'; ++i) {
		num += (str[i] == ch || str[i] == ch - 32) ? 1 : 0;
	}

	std::cout << num;
	return 0;
}