#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	char arr[51] = { "" };
	cin.getline(arr, 51);

	int total = 0;
	int sub_total = 0;
	bool in_brackets = false;
	string curr_num = "";

	for (char& c : arr)
	{
		if (c == '\0')
		{
			if (in_brackets)
			{
				sub_total += stoi(curr_num);
				total -= sub_total;
			}
			else
			{
				total += stoi(curr_num);
			}
			break;
		}

		if (isdigit(c))
		{
			curr_num += c;
		}
		else
		{
			if (!in_brackets) total += stoi(curr_num);
			else sub_total += stoi(curr_num);
			curr_num = "";

			if (c == '-')
			{
				if (!in_brackets) 
					in_brackets = true;
				else
				{
					// 열린 괄호 닫고 새 괄호 열기
					total -= sub_total;
					sub_total = 0;
				}
			}
			else
			{
				// 플러스인 경우
			}
		}
	}

	cout << total;
}