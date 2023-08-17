#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(int& a, int& b)
{
	if (abs(a) == abs(b))
	{
		return a > b;
	}
	else return abs(a) > abs(b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> heap;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			if (heap.empty())
			{
				cout << 0 << "\n";
				continue;
			}
			pop_heap(heap.begin(), heap.end(), Compare);
			cout << *(heap.end() - 1) << "\n";
			heap.pop_back();
		}
		else
		{
			heap.push_back(num);
			push_heap(heap.begin(), heap.end(), Compare);
		}
	}

}