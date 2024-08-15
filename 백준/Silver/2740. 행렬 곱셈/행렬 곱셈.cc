#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n1, m1, n2, m2;
	cin >> n1 >> m1;
	vector<vector<int>> A(n1, vector<int>(m1));
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			cin >> A[i][j];
		}
	}
	
	cin >> n2 >> m2;
	vector<vector<int>> B(n2, vector<int>(m2));
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			cin >> B[i][j];
		}
	}

	vector<vector<int>> C(n1, vector<int>(m2, 0));
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			for (int k = 0; k < n2; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << '\n';
	}
}