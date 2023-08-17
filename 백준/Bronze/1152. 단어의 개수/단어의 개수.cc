#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int count = 0;
	
	string s;
	while (cin >> s)
	{
		count++;
	}
	
	cout << count;
}