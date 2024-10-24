#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int digits[10]; // 0~9
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	while (n > 0)
	{
		digits[n % 10]++;
		n /= 10;
	}
	int sixNine = digits[6] + digits[9];
	if (sixNine % 2 == 0)
		digits[6] = digits[9] = sixNine / 2;
	else
	{
		digits[6] = sixNine / 2;
		digits[9] = sixNine / 2 + 1;
	}
	
	int maxCnt = 0;
	for (int i = 0; i <= 9; i++)
	{
		maxCnt = max(maxCnt, digits[i]);
	}

	cout << maxCnt;
}