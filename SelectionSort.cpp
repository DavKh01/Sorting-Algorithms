#include <iostream>
#include <vector>

void SelectionSort(std::vector<int>& arr)
{
	int k = 0;
	for (int i = 0; i < arr.size() - 1; ++i) {
		k = i;
		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[j] < arr[k]) {
				k = j;
			}
		}
		std::swap(arr[i], arr[k]);
	}
}

int main()
{
	std::vector<int> arr{ 3, 67, -7, 0, 4, 1, 9 };
	SelectionSort(arr);
	for (int k : arr) {
		std::cout << k << " ";
	}
}