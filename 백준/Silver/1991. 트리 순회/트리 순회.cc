#include <iostream>
#include <vector>
#include <queue>
#define INVALID int('.'-'A')
using namespace std;

struct Node
{
	int left = -1;
	int right = -1;
};
vector<Node> nodes(26);

void Preorder(int node_idx)
{
	Node node = nodes[node_idx];
	cout << char(node_idx + 'A');
	if (node.left != INVALID) Preorder(node.left);
	if (node.right != INVALID) Preorder(node.right);
}

void Inorder(int node_idx)
{
	Node node = nodes[node_idx];
	if (node.left != INVALID) Inorder(node.left);
	cout << char(node_idx + 'A');
	if (node.right != INVALID) Inorder(node.right);
}

void Postorder(int node_idx)
{
	Node node = nodes[node_idx];
	if (node.left != INVALID) Postorder(node.left);
	if (node.right != INVALID) Postorder(node.right);
	cout << char(node_idx + 'A');
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// initialisation
	int n = 0;
	cin >> n;

	while (n--)
	{
		char curr = ' ', left = ' ', right = ' ';
		cin >> curr >> left >> right;

		nodes[curr - 'A'].left = left - 'A';
		nodes[curr - 'A'].right = right - 'A';
	}

	Preorder(0);
	cout << "\n";

	Inorder(0);
	cout << "\n";

	Postorder(0);
	cout << "\n";
}