#include <iostream>
#include <vector>
void BubbleSort(std::vector<int>& arr)
{
	bool flag = false;
	for (int i = 0; i < arr.size() - 1; ++i) {
		flag = false;
		for (int j = 0; j < arr.size() - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (!flag) {
			return;
		}
	}
}

int main()
{
	std::vector<int> arr{ 1, 6, -8, 56, 2, -99, 0, 5, 7, 6 };
	BubbleSort(arr);
	for (int k : arr) {
		std::cout << k << " ";
	}
}