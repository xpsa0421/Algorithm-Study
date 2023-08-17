#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
		cout << 1;
	else cout << 0;
}