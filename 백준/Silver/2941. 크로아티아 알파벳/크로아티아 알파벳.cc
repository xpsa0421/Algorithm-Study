#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;

	int ans = 0;
	vector<bool> isAlp(s.size(), false);
	string alp[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	for (string a : alp)
	{
		int idx = s.find(a);
		while (idx != string::npos)
		{
			bool canAdd = true;
			for (int i = 0; i < a.size(); i++)
			{
				if (isAlp[idx + i])
				{
					canAdd = false;
					break;
				}
			}
			if (canAdd)
			{
				for (int i = 0; i < a.size(); i++)
				{
					isAlp[idx + i] = true;
				}
				ans++;
			}
			idx = s.find(a, idx + a.size());			
		}
	}

	for (bool b : isAlp)
	{
		if (!b) ans++;
	}

	cout << ans;
}
