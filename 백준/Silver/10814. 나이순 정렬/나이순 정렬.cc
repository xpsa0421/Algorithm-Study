#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Member
{
	string name;
	int age;
};

bool CompareMembers(Member a, Member b);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Member> members(n);
	for (int i = 0; i < n; i++)
	{
		cin >> members[i].age >> members[i].name;
	}

	stable_sort(members.begin(), members.end(), CompareMembers);

	for (int i = 0; i < n; i++)
	{
		cout << members[i].age << " " << members[i].name << "\n";
	}

	return 0;
}

bool CompareMembers(Member a, Member b)
{
	return a.age < b.age;
}