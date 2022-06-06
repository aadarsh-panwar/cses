#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
const int mod = 1e9+7;

int solve(vector<string> &path, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i =1;i<=n;++i) {
        for(int j = 1;j<=n;++j) {
            if(path[i-1][j-1] == '*')
            continue;
            if(i == 1 && j ==1)
            dp[1][1] = 1;
            else 
            dp[i][j] = dp[i-1][j]%mod + dp[i][j-1]%mod;
        }
    }
    return dp[n][n]%mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >>n;
    vector<string> path(n);
    for(int i=0;i<n;++i) {
        cin >> path[i];
    }
   cout << solve(path, n);
    return 0;
}