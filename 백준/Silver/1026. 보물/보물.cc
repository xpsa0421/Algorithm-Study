#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}

	sort(A.begin(), A.end(), greater<>());	//내림차순
	sort(B.begin(), B.end());				//오름차순
	
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += A[i] * B[i];
	}

	cout << sum;
}