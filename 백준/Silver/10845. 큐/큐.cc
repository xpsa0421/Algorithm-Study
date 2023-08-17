#include <iostream>
using namespace std;

class Queue
{
public:
	int elements[10000];
	int start = 0;
	int end = -1;

public:
	void Push(int x)
	{
		elements[++end] = x;
	};

	int Size()
	{
		return end - start + 1;
	};

	bool Empty()
	{
		return Size() < 1;
	};

	int Front()
	{
		if (Empty()) return -1;
		return elements[start];
	};

	int Back()
	{
		if (Empty()) return -1;
		return elements[end];
	};

	int Pop()
	{
		if (Empty()) return -1;

		int top = Front();
		elements[start++] = -1;
		return top;
	};
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	Queue s;

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
		else if (command == "front")
		{
			cout << s.Front() << "\n";
		}
		else if (command == "back")
		{
			cout << s.Back() << "\n";
		}
	}
}