#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Coord
{
	int x;
	int y;
};

bool CompareCoords(Coord a, Coord b);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Coord> Coords(n);
	for (int i = 0; i < n; i++)
	{
		cin >> Coords[i].x >> Coords[i].y;
	}

	sort(Coords.begin(), Coords.end(), CompareCoords);

	for (int i = 0; i < n; i++)
	{
		cout << Coords[i].x << " " << Coords[i].y << "\n";
	}

	return 0;
}

bool CompareCoords(Coord a, Coord b)
{
	if (a.y == b.y)
	{
		return a.x < b.x;
	}
	return a.y < b.y;
}