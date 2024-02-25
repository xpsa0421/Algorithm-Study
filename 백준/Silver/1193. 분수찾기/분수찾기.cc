#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int x;	cin >> x;
	int end = 0, line = 0;
	while (end < x)
	{
		line++;
		end += line;
	}

	int diff = end - x;
	if (line % 2 == 0)
	{
		cout << line-diff << "/" << diff+1;
	}
	else
	{
		cout << diff+1 << "/" << line-diff;
	}
}

