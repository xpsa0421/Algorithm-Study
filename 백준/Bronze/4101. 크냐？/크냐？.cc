#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int a = 0, b = 0;
	cin >> a >> b;

	while (a != 0 || b != 0)
	{
		cout << (a > b ? "Yes\n" : "No\n");
		cin >> a >> b;
	}
}
