#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Doc
{
	int priority = 0;
	int order = 0;
	Doc(int p, int o) : priority(p), order(o) {};
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_tests;
	cin >> num_tests;

	while (num_tests--)
	{
		queue<Doc> printer;
		vector<int> priorities;

		int num_docs, enquiry;
		cin >> num_docs >> enquiry;

		for (int i = 0; i < num_docs; i++)
		{
			int priority;
			cin >> priority;

			printer.push(Doc(priority, i));
			priorities.push_back(priority);
		}

		sort(priorities.begin(), priorities.end(), [](int a, int b) { return a > b; });
		int idx = 0;

		while (1)
		{
			Doc d = printer.front();
			printer.pop();

			if (d.priority == priorities[idx])
			{
				idx++;
				if (d.order == enquiry)
				{
					cout << idx << "\n";
					break;
				}
			}
			else
			{
				printer.push(d);
			}
		}
	}
}