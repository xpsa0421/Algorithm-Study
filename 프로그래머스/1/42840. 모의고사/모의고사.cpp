#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int typeA[] = {1, 2, 3, 4, 5};
    int typeB[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int typeC[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int sizeA = 5, sizeB = 8, sizeC = 10;
    int ansA = 0, ansB = 0, ansC = 0;
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == typeA[i % sizeA]) ansA++;
        if (answers[i] == typeB[i % sizeB]) ansB++;
        if (answers[i] == typeC[i % sizeC]) ansC++;
    }
    
    int maxVal = max(ansA, max(ansB, ansC));
    if (ansA == maxVal) answer.push_back(1);
    if (ansB == maxVal) answer.push_back(2);
    if (ansC == maxVal) answer.push_back(3);
    
    return answer;
}