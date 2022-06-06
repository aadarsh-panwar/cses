#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    vector<int> coin(n);
    for(int i =0;i<n;++i) {
        cin >> coin[i];
    }
    
    vector<int> dp(s+1, 0);
    dp[0]= 1;
    for(int i =0;i<coin.size();++i) {
        for(int j = 1;j<=s;++j) {
            if(j - coin[i] >= 0) {
                dp[j] += dp[j - coin[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[s];
    return 0;
}