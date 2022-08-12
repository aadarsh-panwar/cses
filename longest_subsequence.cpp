#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int ls(string &a, string &b, int n,int m, vector<vector<int>> &dp) {
    if(n <0 || m <0) {
        return 0;
    }
    if(dp[n][m] != -1)
    return dp[n][m];
    
    if(a[n] == b[m]) {
        return dp[n][m] = 1+ ls(a, b, n-1, m-1, dp);
    }
    return dp[n][m] = max(ls(a, b, n-1, m, dp), ls(a, b, n, m-1, dp));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string a = "AGGTAB";
    string b = "GXTXAYB";
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1, -1));
    int n = a.size();
    int m = b.size();
    ls(a, b, n-1,m-1, dp);
    cout << dp[n-1][m-1] ;
    return 0;
}