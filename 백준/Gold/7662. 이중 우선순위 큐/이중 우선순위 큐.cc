#include <iostream>
#include <set>
using namespace std;

struct node
{
	int key;
	mutable int counter = 1;

	bool operator<(const node& other) const
	{
		return key < other.key;
	}
	bool operator==(const node& other) const
	{
		return key == other.key;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_cases;
	cin >> num_cases;

	while (num_cases--)
	{
		int n;
		cin >> n;
		
		set<node> double_queue;
		for (int i = 0; i < n; i++)
		{
			char oper;
			int num;
			cin >> oper >> num;

			if (oper == 'I')
			{
				node n;
				n.key = num;
				auto iter = double_queue.find(n);
				if (iter != double_queue.end())
				{
					iter->counter++;
				}
				else
				{
					double_queue.insert(n);
				}
			}
			else
			{
				if (double_queue.empty()) continue;
				if (num == -1)
				{
					if (--(double_queue.begin()->counter) == 0)
					{
						double_queue.erase(double_queue.begin());
					}
				}
				else
				{
					if (--(double_queue.rbegin()->counter) == 0)
					{
						double_queue.erase(--double_queue.end());
					}
				}
			}
		}

		if (double_queue.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << double_queue.rbegin()->key << " " << double_queue.begin()->key << "\n";
		}
	}

}