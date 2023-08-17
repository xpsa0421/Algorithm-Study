#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Partition(int start, int end);
void Quicksort(int start, int end);
vector<int> nums;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string s;
	cin >> s;
	for (char& c : s)
	{
		nums.push_back(int(c - '0'));
	}
	
	// Quick sort : partition around the last element
	Quicksort(0, nums.size()-1);
	
	for (auto& n : nums)
	{
		cout << n;
	}
}

int Partition(int start, int end)
{
	int pivot = nums[end];
	int correct_idx = start - 1;

	for (int i = start; i < end; i++)
	{
		if (nums[i] > pivot)
		{
			swap(nums[++correct_idx], nums[i]);
		}
	}
	swap(nums[++correct_idx], nums[end]);
	
	return correct_idx;
}

void Quicksort(int start, int end)
{
	if (start < end)
	{
		int mid = Partition(start, end);
		Quicksort(start, mid - 1);
		Quicksort(mid + 1, end);
	}
}