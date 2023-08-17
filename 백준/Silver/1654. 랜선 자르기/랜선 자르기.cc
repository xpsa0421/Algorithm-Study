#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned int max_len = 0, target;
void BinarySearch(unsigned int start, unsigned int end);
bool CutWires(unsigned int length);

vector<int> lengths;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n >> target;

	for (int i = 0; i < n; i++)
	{
		int length;
		cin >> length;
		lengths.push_back(length);
	}
	sort(lengths.begin(), lengths.end(), greater<>());
	BinarySearch(1, lengths[0]);

	cout << max_len;
}

void BinarySearch(unsigned int start, unsigned int end)
{
	while (start <= end)
	{
		unsigned int mid = ( start + end ) / 2;
		if (CutWires(mid))
		{
			max_len = max(max_len, mid);
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
}

bool CutWires(unsigned int length)
{
	int curr_wires = 0;

	for (auto& wire : lengths)
	{
		curr_wires += wire / length;
		if (curr_wires >= target) return true;
	}
	return false;
}
