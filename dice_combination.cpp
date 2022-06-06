#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;
const long mod = pow(10,9)+7;

long ways(long n) {
    vector<long> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1;i<=n;++i) {
        long res = 0;
        for(int j = 1;j<=6;++j) {
            if(i -j >= 0) {
                res += dp[i-j]%mod;
            }
        }
        dp[i] += res%mod;
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long n;
    cin >>n;
    
    cout << ways(n);
    return 0;
}