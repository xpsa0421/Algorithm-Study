#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> sums[9];

int getRepeatedNum(int N, int repeat) 
{
    int num = 0;
    for (int i = 0; i < repeat; i++)
        num = num * 10 + N;
    return num;
}

int solution(int N, int number) 
{
    if (N == number) return 1;

    for (int i = 1; i < 9; i++) 
    {
        int nn = getRepeatedNum(N, i);
        if (nn == number) return i;
        sums[i].insert(nn);

        for (int j = 1; j < i; j++) 
        {
            for (auto op1 : sums[j]) 
            {
                for (auto op2 : sums[i - j]) 
                {
                    sums[i].insert(op1 + op2);
                    sums[i].insert(op1 - op2);
                    sums[i].insert(op1 * op2);
                    if (op2 != 0) sums[i].insert(op1 / op2);
                }
            }
        }

        if (sums[i].find(number) != sums[i].end()) return i;
    }

    return -1;
}
