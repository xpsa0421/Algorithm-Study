#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// monotone stack algorithm
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_buildings = 0;
	long long int total = 0;
	cin >> num_buildings;
	stack<int> stack;

	for (int i = 0; i < num_buildings; i++)
	{
		int curr = 0;
		cin >> curr;

		while (!stack.empty() && stack.top() <= curr)
		{
			stack.pop();
		}
		stack.push(curr);

		total += stack.size() - 1;
	}

	cout << total;
}