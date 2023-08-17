#include <iostream>
#define MAX_SIZE 10000
using namespace std;

class Deque
{
public:
	int elements[MAX_SIZE];
	int start = -1;
	int rear = -1;
	int size = 0;

public:
	void PushFront(int x)
	{
		if (start == -1 && rear == -1)
		{
			start = rear = 0;
		}
		else if (start == 0)
		{
			start = MAX_SIZE - 1;
		}
		else
		{
			start--;
		}
		elements[start] = x;
		size++;
	};

	void PushBack(int x)
	{
		if (start == -1 && rear == -1)
		{
			start = rear = 0;
		}
		else if (rear == MAX_SIZE - 1)
		{
			rear = 0;
		}
		else
		{
			rear++;
		}
		elements[rear] = x;
		size++;
	};

	int Size()
	{
		return size;
	};

	bool Empty()
	{
		return size == 0;
	};

	int Front()
	{
		if (Empty()) return -1;
		return elements[start];
	}; 

	int Back()
	{
		if (Empty()) return -1;
		return elements[rear];
	};

	int PopFront()
	{
		if (Empty()) return -1;

		int front = Front();
		elements[start] = -1;
		
		if (start == rear)
		{
			start = rear = -1;
		}
		else if (start == MAX_SIZE - 1)
		{
			start = 0;
		}
		else
		{
			start++;
		}

		size--;
		return front;
	};

	int PopBack()
	{
		if (Empty()) return -1;

		int back = Back();
		elements[rear] = -1;

		if (start == rear)
		{
			start = rear = -1;
		}
		else if (rear == 0)
		{
			rear = MAX_SIZE - 1;
		}
		else
		{
			rear--;
		}

		size--;
		return back;
	};
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	Deque s;

	int num_commands;
	cin >> num_commands;

	string command;
	while (num_commands--)
	{
		cin >> command;
		if (command == "push_back")
		{
			int x;
			cin >> x;
			s.PushBack(x);
		}
		else if (command == "push_front")
		{
			int x;
			cin >> x;
			s.PushFront(x);
		}
		else if (command == "pop_front")
		{
			cout << s.PopFront() << "\n";
		}
		else if (command == "pop_back")
		{
			cout << s.PopBack() << "\n";
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