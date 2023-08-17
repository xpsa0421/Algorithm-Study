#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, test_cases;
	cin >> n >> test_cases;
	
	vector<int> sums(n+1);
	cin >> sums[1];

	for (int i = 2; i < n + 1; i++)
	{
		int num;
		cin >> num;
		sums[i] = sums[i - 1] + num;
	}

	while (test_cases--)
	{
		int start, end;
		cin >> start >> end;

		cout << sums[end] - sums[start - 1] << "\n";
	}
}