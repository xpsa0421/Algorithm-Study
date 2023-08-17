#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;
		
	int count = 0;
	for (int start = 0; start < s.length() - (2 * n); start++)
	{
		bool contained = true;
		for (int curr = 0; curr < 2 * n + 1; curr++)
		{
			if (curr % 2 == 0 && s[start + curr] != 'I' ||
				curr % 2 == 1 && s[start + curr] != 'O')
			{
				contained = false;
				break;
			}
		}
		if (contained) count++;
	}

	cout << count;
}