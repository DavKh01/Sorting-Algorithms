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

void Normalize(std::vector<double>& arr, int a, int b)
{
	for (int i = 0; i < arr.size(); ++i) {
		arr[i] = (arr[i] - a) / (b - a);
	}
}

void Denormalize(std::vector<double>& arr, int a, int b)
{
	for (int i = 0; i < arr.size(); ++i) {
		arr[i] = arr[i] * (b - a) + a;
	}
}


double min(std::vector<double>& arr)
{
	double min = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

double max(std::vector<double>& arr)
{
	double max = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
void BucketSort(std::vector<double>& arr)
{
	int size = arr.size();
	std::vector<std::vector<double>> buckets(size);
	int a = min(arr);
	int b = max(arr) + 1;
	Normalize(arr, a , b);
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
	Denormalize(arr, a, b);
}

int main() {
	std::vector<double> arr = { 0.897, 2.565, 1.656, 0.1234, 1.665, 0.3434, 1.56, 3};

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