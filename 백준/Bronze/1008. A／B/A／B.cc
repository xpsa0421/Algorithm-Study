#include <iostream>

int main()
{
    double a, b;
    std::cin >> a >> b;
    std::cout.precision(9);
    std::cout << std::fixed << a / b;
    return 0;
}