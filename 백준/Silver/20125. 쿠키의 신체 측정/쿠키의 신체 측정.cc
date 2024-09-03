#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	// Get record
	vector<vector<char>> map(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	// Find head
	int headI, headJ;
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '*')
			{
				headI = i;
				headJ = j;
				found = true;
				break;
			}
		}
		if (found) break;
	}

	int leftArmLen, rightArmLen, leftLegLen, rightLegLen, bodyLen;
	leftArmLen = rightArmLen = leftLegLen = rightLegLen = bodyLen = 0;

	// Find left arm
	for (int j = headJ - 1; j >= 0; j--)
	{
		if (map[headI + 1][j] == '_') break;
		leftArmLen++;
	}

	// Find right arm
	for (int j = headJ + 1; j < n; j++)
	{
		if (map[headI + 1][j] == '_') break;
		rightArmLen++;
	}

	// Find body
	int legStartI = 0;
	for (int i = headI + 2; i < n; i++)
	{
		if (map[i][headJ] == '_')
		{
			legStartI = i;
			break;
		}
		bodyLen++;
	}

	// Find left leg
	for (int i = legStartI; i < n; i++)
	{
		if (map[i][headJ - 1] == '_') break;
		leftLegLen++;
	}

	// Find right leg
	for (int i = legStartI; i < n; i++)
	{
		if (map[i][headJ + 1] == '_') break;
		rightLegLen++;
	}

	cout << headI + 2 << ' ' << headJ + 1 << '\n';
	cout << leftArmLen << ' ' << rightArmLen << ' ' << bodyLen << ' ' << leftLegLen << ' ' << rightLegLen;
}