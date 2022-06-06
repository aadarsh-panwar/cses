#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

int solve( vector<int> &h) {
    vector<int> dp(h.size() + 1, 0);
    dp[1] = 0;
    for(int i = 2;i<h.size()+1;++i) {
        int a = INT_MAX;
        if(dp[i-1] != INT_MAX) 
        a = abs(h[i] - h[i-1]) + dp[i-1];
        int b = INT_MAX;
        if(dp[i-2] != INT_MAX)
        b = abs(h[i] - h[i-2]) + dp[i-2];
        dp[i] = min(a, b);
    }
    return dp[h.size()];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0;i<n;++i) {
        cin >> v[i];
    }
    cout << solve(v);
    return 0;
}