#include <iostream>
#include <vector>

int main() 
{
	int num_cases;
	std::cin >> num_cases;

	int idx = 0;
	std::vector<char> output;

	for (int i = 0; i < num_cases; i++)
	{
		int num_repeats;
		std::string s;
		std::cin >> num_repeats >> s;

		for (char c : s)
		{
			for (int j = 0; j < num_repeats; j++)
			{
				output.push_back(c);
			}
		}

		if (i + 1 != num_cases)	output.push_back('\n');
	}

	for (auto c : output)
	{
		std::cout << c;
	}

	return 0;
}