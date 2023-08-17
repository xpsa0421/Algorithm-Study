#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, count = 0;
	cin >> n;

	while (n >= 5)
	{
		count += n / 5;
		n /= 5;
	}

	cout << count;
}