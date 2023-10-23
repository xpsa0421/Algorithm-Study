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

	cin >> total;
	for (int i = 1; i <= total; i++)
	{
		cin >> switches[i];
	}

	int num_ppl = 0;
	cin >> num_ppl;
	for (int i = 1; i <= num_ppl; i++)
	{
		cin >> sex[i];
		cin >> nums[i];
	}

	for (int i = 1; i <= num_ppl; i++)
	{
		if (sex[i] == 1) MaleAction(nums[i]);
		else FemaleAction(nums[i]);
	}

	int c = 0;
	for (int i = 1; i <= total; i++)
	{
		cout << switches[i] << " ";
		if (++c == 20)
		{
			c = 0;
			cout << "\n";
		}
	}
}

void FemaleAction(int n)
{
	int start = n - 1, end = n + 1;
	if (start <= 0 || end > total)
	{
		switches[n] = !switches[n];
		return;
	}

	while (start > 0 && end <= total)
	{
		if (switches[start] == switches[end])
		{
			start -= 1;
			end += 1;
		}
		else break;
	}

	for (int i = start + 1; i <= end - 1; i++)
	{
		switches[i] = !switches[i];
	}
}

void MaleAction(int n)
{
	for (int i = n; i <= total;)
	{
		switches[i] = !switches[i];
		i = i + n;
	}
}
