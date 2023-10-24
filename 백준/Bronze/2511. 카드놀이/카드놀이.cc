#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int total = 0;
bool switches[101];
int sex[101];
int nums[101];

void FemaleAction(int n);
void MaleAction(int n);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int nums_A[10];
	int nums_B[10];

	for (int i = 0; i < 10; i++) cin >> nums_A[i];
	for (int i = 0; i < 10; i++) cin >> nums_B[i];

	int points_A = 0, points_B = 0;
	bool lastWin_A = false;
	int numWins = 0;

	for (int i = 0; i < 10; i++)
	{
		if (nums_A[i] == nums_B[i])
		{
			points_A++;
			points_B++;
		}
		else if (nums_A[i] > nums_B[i])
		{
			points_A += 3;
			lastWin_A = true;
			numWins++;
		}
		else
		{
			points_B += 3;
			lastWin_A = false;
			numWins++;
		}
	}

	char winner = 'D';
	if (points_A == points_B)
	{
		if (numWins != 0) winner = lastWin_A ? 'A' : 'B';
	}
	else winner = points_A > points_B ? 'A' : 'B';

	cout << points_A << " " << points_B << "\n";
	cout << winner;
}
