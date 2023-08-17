#include <iostream>

void QuickSort(int arr[], int idx_start, int idx_end);
int Partition(int arr[], int idx_start, int idx_end);

int main() {
	int max, idx_max;
	int arr_init[9], arr_sorted[9];

	// retrieve elements
	for (int i = 0; i < 9; i++)
	{
		std::cin >> arr_init[i];
		arr_sorted[i] = arr_init[i];
	}

	// sort
	QuickSort(arr_sorted, 0, 8);

	// find index
	for (int i = 0; i < 9; i++)
	{
		if (arr_init[i] == arr_sorted[8])
		{
			idx_max = i + 1;
		}
	}

	// print result
	std::cout << arr_sorted[8] << std::endl << idx_max;
	
	return 0;
}


void QuickSort(int arr[], int idx_start, int idx_end)
{
	if (idx_start >= idx_end) return;

	int pivot = arr[idx_end];
	int idx_part = Partition(arr, idx_start, idx_end);
	
	QuickSort(arr, idx_start, idx_part - 1);
	QuickSort(arr, idx_part + 1, idx_end);
}

int Partition(int arr[], int idx_start, int idx_end)
{
	int pivot = arr[idx_end];
	int idx_smaller = idx_start - 1;

	for (int idx_compare = idx_start; idx_compare < idx_end; idx_compare++) {
		if (arr[idx_compare] < pivot)
		{
			idx_smaller++;
			std::swap(arr[idx_smaller], arr[idx_compare]);
		}
	}
	std::swap(arr[idx_smaller + 1], arr[idx_end]);
	return idx_smaller + 1;
}
