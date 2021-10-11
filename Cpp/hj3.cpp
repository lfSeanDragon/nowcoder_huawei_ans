#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int N;
	int num[1000];
	int flag = 0;

	while (cin >> N) {
		for (int i = 0; i < N; ++i) {
			cin >> num[i];
		}
		sort(num, num + N);

		int last = num[0];
		if (flag) {
			cout << endl;
		}
		flag = 1;
		cout << num[0];
		for (int i = 1; i < N; ++i) {
			if (num[i] != last) {
				cout << endl << num[i];
				last = num[i];
			}
		}
	}

	return 0;
}