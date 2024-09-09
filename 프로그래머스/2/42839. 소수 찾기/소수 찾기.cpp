#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <math.h>

using namespace std;

bool IsPrime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> nums;
    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.size(); i++)
        {
            int t = stoi(numbers.substr(0, i));
            if (IsPrime(t)) nums.insert(t);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return nums.size();
}