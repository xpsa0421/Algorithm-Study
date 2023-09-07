#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	string str;
	cin >> str;

	int count = 0;
	char prev = ' ';
	stack<char> s;
	for (auto& c : str)
	{
		// 이전 괄호가 여는 괄호였을 경우
		if (!s.empty() && prev == '(')
		{
			if (c == ')')
			{
				// 레이저
				s.pop(); // 이전 ( 제거
				count += s.size();

			}
			else
			{
				s.push('(');
			}
		}
		// 이전 괄호가 닫는 괄호였을 경우
		else
		{
			if (c == ')')
			{
				// 막대기의 끝
				s.pop();
				count++;
			}
			else
			{
				// 막대기 또는 레이저의 시작
				s.push('(');
			}
		}
		prev = c;
	}

	cout << count;
}