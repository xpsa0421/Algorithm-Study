#include <iostream>
#include <vector>
using namespace std;

struct Queue
{
private:
	vector<int> contents;
	int front = 0;
	int back = -1;

public:
	void Push(int x)
	{
		contents.push_back(x);
		back++;
	}

	void Pop()
	{
		if (back < front)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << contents[front] << "\n";
			contents[front++] = 0;
		}
	}

	void Size()
	{
		if (back < front) cout << 0 << "\n";
		else cout << (back - front + 1) << "\n";
	}

	void Empty()
	{
		cout << (back < front) << "\n";
	}

	void Front()
	{
		if (back < front)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << contents[front] << "\n";
		}
	}

	void Back()
	{
		if (back < front) cout << -1 << "\n";
		else cout << contents[back] << "\n";
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	Queue q;
	int num_commands = 0;
	cin >> num_commands;

	while (num_commands--)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int n;
			cin >> n;
			q.Push(n);
		}
		else if (s == "pop")
		{
			q.Pop();
		}
		else if (s == "size")
		{
			q.Size();
		}
		else if (s == "empty")
		{
			q.Empty();
		}
		else if (s == "front")
		{
			q.Front();
		}
		else if (s == "back")
		{
			q.Back();
		}
	}
}