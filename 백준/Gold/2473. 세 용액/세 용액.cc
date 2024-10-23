#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> liquids(n,0);
	vector<int> candIndices; long long curMin = 3000000000;
	for (int i = 0; i < n; i++) cin >> liquids[i];
	sort(liquids.begin(), liquids.end());

	for (int a = 0; a < n - 2; a++)
	{
		int b = a + 1, c = n - 1;
		int target = -liquids[a];

		while (b < c)
		{
			if (abs((long long)liquids[a] + liquids[b] + liquids[c]) < curMin)
			{
				curMin = abs((long long)liquids[a] + liquids[b] + liquids[c]);
				candIndices = { a,b,c };
				if (curMin == 0) break;
			}
			if (liquids[b] + liquids[c] < target) b++;
			else c--;
		}
	}

	cout << liquids[candIndices[0]] << ' ' << liquids[candIndices[1]] << ' ' << liquids[candIndices[2]];
}