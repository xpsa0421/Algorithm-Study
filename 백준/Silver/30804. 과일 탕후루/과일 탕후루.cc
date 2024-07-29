#include <iostream>
#include <map>
using namespace std;

int arr[200005];
map<int, int>m;

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int start, end;
    int maxs = -1;

    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    start = 0;
    end = 1;
    m[arr[start]]++;
    m[arr[end]]++;

    while (1) 
    {
        if (end == n) 
        {
            maxs = Max(maxs, end - start);
            break;
        }
        // 다음 과일 보기
        if (m.size() <= 2) 
        {
            end++;
            m[arr[end]]++;
        }
        // 과일 개수가 두 종류 이상을 초과했을 경우
        if (m.size() > 2) 
        {
            maxs = Max(maxs, end - start);
            m[arr[start]]--;
            // 만약 이 과일이 더 이상 안나타나면 제거
            if (m[arr[start]] == 0) 
            {
                m.erase(arr[start]);
            }
            start++;
        }
    }
    cout << maxs;
    return 0;
}