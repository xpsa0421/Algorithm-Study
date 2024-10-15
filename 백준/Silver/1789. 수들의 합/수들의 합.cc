#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// 더해서 S를 만들 수 있는 서로 다른 최대 N개의 자연수 -> N 구하기
	long long s;
	cin >> s;

	long long k = (-1 + sqrt(1 + 8 * s)) / 2;
	cout << k;
}