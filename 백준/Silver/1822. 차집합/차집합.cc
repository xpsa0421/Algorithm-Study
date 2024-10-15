#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// 집합 A에는 속하고 B에는 속하지 않는 모든 원소 구하기
	int numA, numB;
	cin >> numA >> numB;

	vector<int> A(numA, 0);
	vector<int> B(numB, 0);
	for (int i = 0; i < numA; i++) cin >> A[i];
	for (int i = 0; i < numB; i++) cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<int> ans;
	for (int a : A)
	{
		if (!binary_search(B.begin(), B.end(), a))
			ans.push_back(a);
	}

	cout << ans.size() << '\n';
	for (int a : ans) cout << a << ' ';
}