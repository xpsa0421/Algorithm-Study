#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;

	// Count
	int red = 0, blue = 0;
	for (char c : s)
	{
		if (c == 'R') red++;
		else blue++;
	}
	if (red == 0 || blue == 0)
	{
		cout << 0;
		return 0;
	}

	// 1. 빨간 볼을 왼쪽 끝에 모으는 경우
	int atEnd = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'B') break;
		atEnd++;
	}
	ans = red - atEnd;
	
	// 2. 빨간 볼을 오른쪽 끝에 모으는 경우
	atEnd = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'B') break;
		atEnd++;
	}
	ans = min(ans, red - atEnd);

	// 3. 파란 볼을 왼쪽 끝에 모으는 경우
	atEnd = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'R') break;
		atEnd++;
	}
	ans = min(ans, blue - atEnd);
	
	// 4. 파란 볼을 오른쪽 끝에 모으는 경우
	atEnd = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'R') break;
		atEnd++;
	}
	ans = min(ans, blue - atEnd);

	cout << ans;
}