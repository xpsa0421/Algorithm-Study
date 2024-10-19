#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string preAst, postAst;

bool isMatch(string name)
{
	int prevPos = name.find(preAst);
	if (prevPos != 0) return false;

	name = name.substr(preAst.size());
	int postPos = name.rfind(postAst);
	if (postPos != name.size() - postAst.size()) return false;

	return true;
}

int main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;	cin >> n;
	string pattern;	cin >> pattern;
	int astPos = pattern.find('*');
	preAst = pattern.substr(0, astPos);
	postAst = pattern.substr(astPos + 1);

	while (n--)
	{
		string name;
		cin >> name;
		cout << (isMatch(name) ? "DA\n" : "NE\n");		
	}
}
