#include <iostream>
#include <vector>
using namespace std;

struct Body
{
	int weight;
	int height;
	int order = 0;
	Body(int w, int h) : weight(w), height(h) {};
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Body> list;
	for (int i = 0; i < n; i++)
	{
		int w, h;
		cin >> w >> h;
		list.push_back(Body(w, h));
	}

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		int weight = list[i].weight;
		int height = list[i].height;

		for (int j = 0; j < n; j++)
		{
			if (weight < list[j].weight && height < list[j].height)
				count++;
		}

		list[i].order = count + 1;
	}

	for (int i = 0; i < n; i++)
	{
		cout << list[i].order << " ";
	}
}