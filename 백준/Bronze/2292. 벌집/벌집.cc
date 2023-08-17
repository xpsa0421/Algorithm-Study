#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> start_numbers = { 0, 1, 2 };
	
	if (n < 8)
	{
		if (n == 1) cout << 1;
		else cout << 2;
		return 0;
	}

	for (int i = 3;; i++)
	{
		start_numbers.push_back(start_numbers[i - 1] + 6 * (i - 2));
		if (n < start_numbers[i])
		{
			cout << i - 1;
			break;
		}
	}
}