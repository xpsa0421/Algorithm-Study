#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
string map[64];

void compress(int stR, int stC, int size)
{
	// Can it be compressed directly?
	int sum = 0;
	for (int r = stR; r < stR + size; r++)
		for (int c = stC; c < stC + size; c++)
			sum += (map[r][c] - '0');
	
	if (sum == size * size)
	{
		cout << 1;
		return;
	}
	else if (sum == 0)
	{
		cout << 0;
		return;
	}

	// Need more compression
	cout << '(';
	int newSize = size / 2;
	compress(stR, stC, newSize);
	compress(stR, stC + newSize, newSize);
	compress(stR + newSize, stC, newSize);
	compress(stR + newSize, stC + newSize, newSize);
	cout << ')';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	compress(0, 0, n);
}