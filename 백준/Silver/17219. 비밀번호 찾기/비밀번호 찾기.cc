#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_site, num_inquiry;
	cin >> num_site >> num_inquiry;

	unordered_map<string, string> site_to_pw(num_site);

	while (num_site--)
	{
		string site, pw;
		cin >> site >> pw;
		site_to_pw.insert({ site, pw });
	}

	while (num_inquiry--)
	{
		string inquiry;
		cin >> inquiry;
		cout << (*site_to_pw.find(inquiry)).second << "\n";
	}
}
