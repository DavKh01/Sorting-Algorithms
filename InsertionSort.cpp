#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& arr)
{
	for (int i = 1; i < arr.size(); ++i) {
		int k = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > k) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = k;
	}
}