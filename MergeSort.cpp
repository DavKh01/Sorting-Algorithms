#include <iostream>
#include <vector>

void Merge(std::vector<int>& arr, int start, int mid, int end) 
{
	int s1 = start;
	int e1 = mid;
	int s2 = mid + 1;
	int e2 = end;
	std::vector<int> tmp;
	while (s1 <= e1 && s2 <= e2) {
		if (arr[s1] < arr[s2]) {
			tmp.push_back(arr[s1]);
			++s1;
		}
		else {
			tmp.push_back(arr[s2]);
			++s2;
		}
	}
	while (s1 <= e1) {
		tmp.push_back(arr[s1++]);
	}
	while (s2 <= e2) {
		tmp.push_back(arr[s2++]);
	}
	for (int i = 0; i < tmp.size(); ++i) {
		arr[start + i] = tmp[i];
	}
}

void MergeSort(std::vector<int>& arr, int start, int end)
{
	if (start < end) {
		int mid = start + (end - start) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}

int main()
{
	std::vector<int> arr = { 0, 5, -1, -3, 7, 10, 3 };
	MergeSort(arr, 0, arr.size() - 1);
	for (int k : arr) {
		std::cout << k << " ";
	}
}