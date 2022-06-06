#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

int change(const vector<int> &coin, int amt) {
    vector<int> dp(amt+1, INT_MAX);
    dp[0] = 0;
    for(int i =1;i<=amt;++i) {
        for(int j =0;j<coin.size();++j) {
            if(i - coin[j] >=0) {
                int sub_res = dp[i - coin[j]];
                if(sub_res != INT_MAX && sub_res + 1 < dp[i])
                dp[i] = sub_res+1;
            }
        }
    }
    if(dp[amt] == INT_MAX)
    return -1;
    return dp[amt];
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
    cout << change(coin,s);
    return 0;
}