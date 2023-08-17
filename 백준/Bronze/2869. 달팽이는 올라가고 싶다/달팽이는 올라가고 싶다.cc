#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int up, down, target;
	cin >> up >> down >> target;

	int days = (target - up) / (up - down);
	if ((target - up) % (up - down) == 0)
	{
		cout << days + 1;
	}
	else cout << days + 2;
}