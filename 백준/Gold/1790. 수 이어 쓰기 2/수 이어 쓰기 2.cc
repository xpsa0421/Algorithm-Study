#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k, prev_digits = 0, total_digits = 0;
int FindKthNumber(int start);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n >> k;

	int length = to_string(n).length();
	int start = 1;
	int answer = -1;

	for (int num_digits = 1; num_digits <= length; num_digits++)
	{
		prev_digits = total_digits;
		if (num_digits == length)
		{
			total_digits += num_digits * (n - start + 1);
		}
		else
		{
			total_digits += (num_digits * ((start * 10 - 1) - start + 1));
		}
		if (answer == -1 && total_digits >= k)
		{
			answer = FindKthNumber(start);
			break;
		}
		start *= 10;
	}

	cout << answer;
	return 0;
}

int FindKthNumber(int start)
{
	// prev_digits ~ total_digits 사이에 k가 존재함
	// min번째 숫자는 start의 첫번째 숫자 (1)
	int min = prev_digits + 1;
	int num_len = to_string(start).length();
	int num_ = (k - min) / num_len;
	int index = (k - min) % num_len;

	int num = start + num_;
	int digit = to_string(num)[index] - '0';
	return digit;
}