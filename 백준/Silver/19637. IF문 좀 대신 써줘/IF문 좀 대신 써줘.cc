#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0, t = 0;
	cin >> n >> t;

	string name = "";
	int upper = 0;
	vector<int> uppers(n, 0);
	vector<string> names(n, "");
	for (int i = 0; i < n; i++)
	{
		cin >> names[i] >> uppers[i];
	}
	vector<int> tests(t,0);
	for (int i = 0; i < t; i++)
	{
		cin >> tests[i];
	}	
	
	// solve
	for (int test : tests)
	{
		auto iter = lower_bound(uppers.begin(), uppers.end(), test);
		int idx = iter - uppers.begin();
		cout << names[idx] << "\n";
	}	

	// output

}
