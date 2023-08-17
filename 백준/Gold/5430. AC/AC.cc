#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_tests = 0;
	cin >> num_tests;

	while (num_tests--)
	{
		// input
		int size = 0;
		string functions = "";
		cin >> functions >> size;

		vector<int> nums;
		string nums_str = "";
		cin >> nums_str;
		
		if (size != 0)
		{
			string temp = "";

			for (char& c : nums_str)
			{
				if (c == ',' || c == ']')
				{
					nums.push_back(stoi(temp));
					temp = "";
				}
				else if (isdigit(c))
				{
					temp += c;
				}
			}
		}
		
		// functions
		bool order_reverse = false;
		bool error = false;
		int front = 0; int back = size - 1;
		for (char& function : functions)
		{
			if (function == 'R')
			{
				// 순서 뒤집기
				order_reverse = !order_reverse;
			}
			else
			{
				if (size == 0)
				{
					error = true;
					break;
				}

				// 첫번째 수 버리기
				if (order_reverse)
				{
					nums[back] = -1;
					back--;
					size--;
				}
				else
				{
					nums[front] = -1;
					front++;
					size--;
				}
			}
		}

		string res = "";
		if (error)
		{
			res = "error";
		}
		else
		{
			res += "[";
			if (order_reverse)
			{
				for (int i = back; i >= front; i--)
				{
					res += to_string(nums[i]);
					if (i != front) res += ",";
				}
			}
			else
			{
				for (int i = front; i <= back; i++)
				{
					res += to_string(nums[i]);
					if (i != back) res += ",";
				}
			}
			
			res += ']';
		}
		cout << res << "\n";
	}
}