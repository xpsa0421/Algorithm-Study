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

	int a, b;
	cin >> a; vector<int> A(a, 0);
	for (int i = 0; i < a; i++) cin >> A[i];
	cin >> b; vector<int> B(b, 0);
	for (int i = 0; i < b; i++) cin >> B[i];

	vector<int> ans;
	int aStart = 0, bStart = 0;
	while (true)
	{
		int aMax = 0, aMaxIdx = 0;
		bool isInB = false;

		// Find max in A
		for (int i = aStart; i < a; i++)
		{
			if (A[i] > aMax)
			{
				aMax = A[i];
				aMaxIdx = i;
			}
		}
		if (aMax == 0) break;

		// Does that number exist in B?
		for (int j = bStart; j < b; j++)
		{
			if (B[j] == aMax)
			{
				ans.push_back(aMax);
				aStart = aMaxIdx + 1; // max idx 이후부터 검색
				bStart = j + 1;
				isInB = true;
				break;
			}
		}

		// If does not exist, search for the next max
		if (!isInB) A[aMaxIdx] = 0;
	}
	
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
}