#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string doc;
	string target;
	getline(cin, doc);
	getline(cin, target);

	int i = 0;
	int count = 0;
	int target_len = target.length();
	int doc_len = doc.length();
	int start = 0;

	while (start <= doc_len - target_len)
	{
		if (doc[start] != target[0])
		{
			start++;
		}
		else
		{
			if (doc[start + i] == target[i])
			{
				i++;
				if (i == target_len)
				{
					count++;
					start += target_len;
					i = 0;
				}
			}
			else
			{
				i = 0;
				start++;
			}
		}
	}

	cout << count;
}
