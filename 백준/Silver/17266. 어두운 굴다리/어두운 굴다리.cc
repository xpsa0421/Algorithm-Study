#include <iostream>
#include <algorithm>
#include <vector>
#include<math.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	float ans = 0;
	int prevPos = 0, pos = 0;

	// 첫 가로등
	cin >> pos;
	ans = pos;
	prevPos = pos;	

	// 중간 가로등
	for (int i = 1; i < m; i++)
	{
		cin >> pos;
		ans = max(ans, (pos - prevPos) / 2.0f);
		prevPos = pos;
	}

	// 마지막 가로등
	ans = max(ans, float(n - prevPos));
	cout << (int)(ceil(ans));
}