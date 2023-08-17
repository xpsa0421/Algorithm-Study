#include <iostream>
using namespace std;

class Stack
{
public:
	int elements[10000] = { -1 };
	int size = 0;

public:
	void Push(int x)
	{
		elements[size] = x;
		size++;
	};

	int Size()
	{
		return size;
	};

	bool Empty()
	{
		return Size() < 1;
	};

	int Top()
	{
		if (Empty()) return -1;
		return elements[size - 1];
	};

	int Pop()
	{
		if (Empty()) return -1;

		int top = Top();
		elements[size - 1] = -1;
		size--;
		return top;
	};
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	Stack s;

	int num_commands;
	cin >> num_commands;

	string command;
	while (num_commands--)
	{
		cin >> command;
		if (command == "push")
		{
			int x;
			cin >> x;
			s.Push(x);
		}
		else if (command == "pop")
		{
			cout << s.Pop() << "\n";
		}
		else if (command == "size")
		{
			cout << s.Size() << "\n";
		}
		else if (command == "empty")
		{
			cout << (s.Empty() ? 1 : 0) << "\n";
		}
		else if (command == "top")
		{
			cout << s.Top() << "\n";
		}
	}
}