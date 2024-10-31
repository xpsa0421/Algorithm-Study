#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i != 0) continue;
        int yRow = i;
        int yCol = yellow / yRow;
        
        int b = yRow * 2 + yCol * 2 + 4;
        if (b == brown)
            return {yCol + 2, yRow + 2};
    }
}