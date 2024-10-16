#include <iostream>
#include <algorithm>
#include <vector>

int GetMax(std::vector<int>& arr)
{
	return *std::max_element(arr.begin(), arr.end());
}

void CountingSort(std::vector<int>& arr, int exp)
{
	int n = arr.size();
	std::vector<int> output(n);
	int count[10]{ 0 };
	for (int i = 0; i < n; ++i) {
		++count[(arr[i] / exp) % 10];
	}
	for (int i = 1; i < 10; ++i) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; --i) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < arr.size(); ++i) {
		arr[i] = output[i];
	}
}

void RadixSort(std::vector<int>& arr)
{
	int m = GetMax(arr);
	for (int exp = 1; m / exp > 0; exp *= 10) {
		CountingSort(arr, exp);
	}
}

int main() {
	std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
	RadixSort(arr);
	for (int k : arr) {
		std::cout << k << " ";
	}
}