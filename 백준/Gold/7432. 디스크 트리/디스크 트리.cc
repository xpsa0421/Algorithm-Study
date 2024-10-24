#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int ROOT = 0;
const int MX = 500 * 40 + 5;
int unused = 1;
unordered_map<string, int> nxt[MX]; // nxt[v][s]: v번 노드의 자식 s의 노드 번호
string names[MX];
int depths[MX];

void insert(vector<string>& route)
{
	int v = ROOT;
	for (auto s : route)
	{
		int nextV = nxt[v][s];
		if (nextV == 0)	nextV = nxt[v][s] = unused++;
		names[nextV] = s;
		depths[nextV] = depths[v] + 1;
		v = nextV;
	}
}

void print(int v)
{
	// print itself
	if (v != ROOT)
	{
		for (int i = 0; i < depths[v]; i++) cout << ' ';
		cout << names[v] << '\n';
	}

	// print children
	vector<pair<string, int>> vec(nxt[v].begin(), nxt[v].end());
	sort(vec.begin(), vec.end());
	for (auto child : vec) print(child.second);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	depths[ROOT] = -1;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string path; cin >> path; 
		string directory = "";
		vector<string> separated;

		for (char c : path)
		{
			if (c == '\\')
			{
				separated.push_back(directory);
				directory = "";
			}
			else directory += c;
		}
		separated.push_back(directory);
		insert(separated);
	}
	print(ROOT);
}