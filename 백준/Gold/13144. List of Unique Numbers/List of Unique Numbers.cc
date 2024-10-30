#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool appeared[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long ans = 0;
    long long st = 0, en = 0;
    while (st < n)
    {
        int cnt = 0;
        while (en < n)
        {
            if (appeared[nums[en]]) break;
            appeared[nums[en]] = true;
            en++;
        }
        ans += en - st;
        appeared[nums[st]] = false;
        st++;
    }    
    
    cout << ans;
}
