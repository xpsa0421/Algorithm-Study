#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, curr = 666, temp, curr_count = 1;
	cin >> n;

	while (curr_count != n)
	{
		curr++;
		temp = curr;
		while (temp >= 666)
		{
			if (temp % 1000 == 666)
			{
				curr_count++;
				break;
			}
			else temp /= 10;
		}
	}
	cout << curr;
}