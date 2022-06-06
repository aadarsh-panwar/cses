#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
typedef vector<int> vi;
int solve(vi& book, vi & page, int amt, int n) {
    vector<vector<int>> dp(n+1, vector<int>(amt+1, 0));
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=amt;++j) {
            if(book[i-1] <= j) {
                dp[i][j] = max<int>(page[i-1] + dp[i-1][j- book[i-1]], 
                                    dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amt];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> b(n);
    vector<int> p(n);
    for(int i=0;i<n;++i) {
        cin >>b[i];
    }
    for(int i=0;i<n;++i) {
        cin >> p[i];
    }
    cout << solve(b, p, x, n-1);
    return 0;
}