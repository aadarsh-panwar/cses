#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

const int mod  = 1e9+7;

int combination(int n, const vector<int> &coin, vector<int> &dp) {
    if(dp[n] != -1)
    return dp[n];
    if(n < 0)
    return 0;
    if(n == 0)
    return 1;
    int res = 0;
    for(int i = 0;i<coin.size();++i) {
        if(n - coin[i] >= 0)
        res  += combination(n- coin[i], coin, dp);
        res %= mod;
    }
    dp[n] = res;
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    vector<int> coin(n);
    for(int i =0;i<n;++i) {
        cin >> coin[i];
    }
    
    vector<int> dp(s+1, -1);
    dp[0] = 1;
    combination(s, coin, dp);
    cout << dp[s];
    return 0;
}