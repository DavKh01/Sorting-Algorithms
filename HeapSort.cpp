#include <iostream>
#include <vector>

void Heapify(std::vector<int>& arr, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}

void HeapSort(std::vector<int>& arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; --i) {
		Heapify(arr, n, i);
	}
	for (int i = n - 1; i > 0; --i) {
		std::swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

int main() {
	std::vector<int> arr = { 0, 5, -1, -3, 7, 10, 3 };
	HeapSort(arr);
	for (int k : arr) {
		std::cout << k << " ";
	}
}