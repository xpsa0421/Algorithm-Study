#include <iostream>
using namespace std;

int heap[100001] = { 0 };
int h_size = 0;

void Push(int n);
void Pop();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, enquiry;
	cin >> n;

	while (n--)
	{
		cin >> enquiry;
		if (enquiry == 0) Pop();
		else Push(enquiry);
	}
}

void Push(int n)
{
	heap[++h_size] = n;
	int i = h_size;

	while (i > 1 && heap[i/2] < n)
	{
		swap(heap[i / 2], heap[i]);
		i = i / 2;
	}
}

void Pop()
{
	if (h_size == 0)
	{
		cout << 0 << "\n";
		return;
	}
	cout << heap[1] << "\n";
	heap[1] = heap[h_size];
	heap[h_size--] = 0;

	int parent = 1;
	int child = 2;
	while (child <= h_size)
	{
		if (child + 1 <= h_size && heap[child] < heap[child + 1])
		{
			child++;
		}
		if (heap[child] <= heap[parent])
		{
			break;
		}
		swap(heap[parent], heap[child]);
		parent = child;
		child *= 2;
	}	
}
