#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> scores(n);
	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}
	sort(scores.begin(), scores.end());

	int sum = 0;
	int out_p = round(n * 0.15);
	int count = n - out_p * 2;
	 
	for (int i = out_p; i < n - out_p; i++)
	{
		sum += scores[i];
	}
	if (count != 0)
	{
		cout << round(float(sum) / (count));
	}
	else
	{
		cout << 0;
	}
}