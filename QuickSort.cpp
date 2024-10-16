#include <iostream>
#include <vector>

int Partition(std::vector<int>& arr, int start, int end)
{
	int pivot = arr[end];
	int i = start - 1;
	for (int j = start; j < end; ++j) {
		if (arr[j] <= pivot) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[end]);
	return i + 1;
}

void QuickSort(std::vector<int>& arr, int start, int end)
{
	if (start < end) {
		int pi = Partition(arr, start, end);
		QuickSort(arr, start, pi - 1);
		QuickSort(arr, pi + 1, end);
	}
}

int main() {
	std::vector<int> arr = { 0, 5, -1, -3, 7, 10, 3 };
	QuickSort(arr, 0, arr.size() - 1);
	for (int k : arr) {
		std::cout << k << " ";
	}
}