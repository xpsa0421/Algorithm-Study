#include <iostream>
using namespace std;

struct Heap
{
	int elements[100001] = { 0 }; // insert from 1
	int size = 0;

	void Insert(int x)
	{
		int idx = ++size;
		elements[idx] = x;
		
		while (idx != 1 && elements[idx] < elements[idx / 2])
		{
			swap(elements[idx], elements[idx / 2]);
			idx = idx / 2;
		}
	}

	void Delete()
	{
		if (size == 0)
		{
			cout << 0 << "\n";
			return;
		}

		cout << elements[1] << "\n";
		size--;

		if (size > 0)
		{
			elements[1] = elements[size + 1];
			elements[size + 1] = 0;
		}

		int idx = 1;
		while (idx * 2 <= size)
		{
			// 자식이 있으면 비교해서 더 작은 인덱스 찾기
			int min_idx = elements[idx * 2] < elements[idx] ? idx * 2 : idx;
			if (idx * 2 + 1 <= size)
			{
				min_idx = elements[idx * 2 + 1] < elements[min_idx] ? idx * 2 + 1 : min_idx;
			}

			// 부모보다 자식이 더 작으면 스왑
			if (idx != min_idx)
			{
				swap(elements[idx], elements[min_idx]);
				idx = min_idx;
			}
			else
			{
				break;
			}
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, x;
	cin >> n;

	Heap h;
	while (n--)
	{
		cin >> x;
		if (x == 0)
		{
			h.Delete();
		}
		else
		{
			h.Insert(x);
		}
	}
}