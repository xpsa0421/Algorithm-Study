#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;

	vector<int> weights(n);
	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	// solve
	sort(weights.begin(), weights.end(), greater()); //내림차순
	int max_w = -1;
	for (int k = 1; k <= n; k++)
	{
		max_w = max(weights[k - 1] * k, max_w);
	}

	cout << max_w;
}