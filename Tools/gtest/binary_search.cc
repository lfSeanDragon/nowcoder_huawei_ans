#include <stdio.h>
#include <gtest/gtest.h>

int binary_search(const int arr[], int start, int end, int key)
{
	int ret = -1;

	int mid;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (arr[mid] < key) {
			start = mid + 1;
		} else if (arr[mid] > key) {
			end = mid - 1;
		} else {
			ret = mid;
			break;
		}
	}
	return ret;
}

TEST(HelloTest, BasicAssertions)
{
	int data[20] = {
		0, 2, 4, 5, 7, 68, 75, 98, 124, 255, 348, 485, 515, 648, 754, 800, 954, 1245, 1588, 1915,
	};
	for (int i = 0; i < 2000; ++i) {
		EXPECT_EQ(i, data[binary_search(data, 0, 19, i)]);
	}
}
