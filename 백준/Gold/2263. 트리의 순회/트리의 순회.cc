#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
vector<int> inIndex; // 노드별 inorder 벡터에서의 인덱스

void solve(int inStart, int inEnd, int postStart, int postEnd)
{
	// Base case
	if (inStart > inEnd || postStart > postEnd) return;

	// Output
	int rootVal = postorder[postEnd];
	cout << rootVal << ' ';

	// Divide
	int inRoot = inIndex[rootVal];
	int leftSize = inRoot - inStart;
	int rightSize = inEnd - inRoot;

	// Conquer
	solve(inStart, inRoot - 1, postStart, postStart + leftSize - 1);
	solve(inRoot + 1, inEnd, postEnd - rightSize, postEnd - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// Input
	cin >> n;
	inorder.resize(n, 0);
	postorder.resize(n, 0);
	inIndex.resize(n+1, 0);
	
	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
		inIndex[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> postorder[i];

	// Solve
	solve(0, n - 1, 0, n - 1);
}
