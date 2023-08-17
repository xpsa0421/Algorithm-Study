#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int methods[1001];
	methods[1] = 1;
	methods[2] = 2;

	for (int i = 3; i < n + 1; i++)
	{
		methods[i] = (methods[i - 1] + methods[i - 2]) % 10007;
	}

	cout << methods[n] % 10007;
}