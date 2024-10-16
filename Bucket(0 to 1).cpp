#include <iostream>
#include <vector>
void InsertionSort(std::vector<double>& arr)
{
	int size = arr.size();
	for (int i = 1; i < size; ++i) {
		double key = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > key) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = key;
	}
}

void BucketSort(std::vector<double>& arr)
{
	int size = arr.size();
	std::vector<std::vector<double>> buckets(size);
	for (int i = 0; i < size; ++i) {
		buckets[int(arr[i] * size)].push_back(arr[i]);
	}
	int k = 0;
	for (int i = 0; i < size; ++i) {
		InsertionSort(buckets[i]);
		for (int j = 0; j < buckets[i].size(); ++j) {
			arr[k++] = buckets[i][j];
		}
	}
}

int main() {
	std::vector<double> arr = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };

	std::cout << "Unsorted array: ";
	for (double num : arr) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	BucketSort(arr);

	std::cout << "Sorted array: ";
	for (double num : arr) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}