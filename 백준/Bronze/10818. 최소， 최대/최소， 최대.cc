#include <iostream>

int main()
{
	int n, min, max;
	std::cin >> n;

	int first;
	std::cin >> first;
	min = max = first;

	for (int i = 1; i < n; i++)
	{
		int num;
		std::cin >> num;
		
		if (num < min) min = num;
		else if (num > max) max = num;
	}

	std::cout << min << " " << max;

	return 0;
}