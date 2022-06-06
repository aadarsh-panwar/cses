#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int solve(int n) {
    if(n == 0)
    return 0;
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int  i=1;i<=n;++i) {
        int num = i;
    while(num > 0) {
        int dig = num%10;
        num /= 10;
        if(dig ==0)
        continue;
        dp[i] = min(dp[i], dp[i-dig]+1);
    }
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}