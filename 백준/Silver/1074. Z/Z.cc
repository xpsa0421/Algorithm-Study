#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int target_r = 0;
int target_c = 0;
int order = 0;

void VisitZ(int n, int topleft_r, int topleft_c);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, visit_order = 0;
	cin >> n >> target_r >> target_c;

	VisitZ(pow(2, n), 0, 0);
}

void VisitZ(int n, int topleft_r, int topleft_c)
{
	if (topleft_r == target_r && topleft_c == target_c)
	{
		cout << order;
		return;
	}

	if (topleft_r <= target_r && target_r < topleft_r + n
		&& topleft_c <= target_c && target_c < topleft_c + n)
	{
		VisitZ(n / 2, topleft_r, topleft_c);
		VisitZ(n / 2, topleft_r, topleft_c + n / 2);
		VisitZ(n / 2, topleft_r + n / 2, topleft_c);
		VisitZ(n / 2, topleft_r + n / 2, topleft_c + n / 2);
	}
	else
	{
		order += n * n;
	}
}