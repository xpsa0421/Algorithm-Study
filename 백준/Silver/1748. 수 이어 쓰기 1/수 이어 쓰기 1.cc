#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int total_digits = 0;
	int length = to_string(n).length();
	int start = 1;

	for (int num_digits = 1; num_digits <= length; num_digits++)
	{
		if (num_digits == length)
		{
			total_digits += num_digits * (n - start + 1);
		}
		else
		{
			total_digits += (num_digits * ((start * 10 - 1) - start + 1));
			start *= 10;
		}
	}

	cout << total_digits;
	return 0;
}
