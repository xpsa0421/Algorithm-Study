#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_set>
using namespace std;
#define MAX 0x7f7f7f7f

int n;
vector<int> inorder;

void convert(int l, int r)
{
	if (l >= r) return;
	if (l == r - 1)
	{
		cout << inorder[l] << '\n';
		return;
	}

	int root = inorder[l]; 
	int mid = l + 1;
	while (mid < r)
	{
		if (inorder[mid] > root) break;
		mid++;
	}

	convert(l + 1, mid);
	convert(mid, r);
	cout << root << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int num;
	while (cin >> num)
		inorder.push_back(num);

	convert(0, inorder.size());
}
