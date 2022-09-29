#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
#include<unordered_set>
using namespace std;

bool solve(string str, unordered_set<string> &dict, vector<int> &dp) {
    if(str.size() ==0 )
    return true;
    int n = str.size();
    if(dp[n] != -1)
    return dp[n];
    dp[n] = 0;
    for(int i = 1;i<=str.size();++i) {
        string sub = str.substr(0, i);
        if(dict.find(sub) != dict.end() && solve(str.substr(i), dict,dp)) {
            return dp[n] = 1;
        }
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string str = "leetcode";
    vector<string> dict = {"leet", "code"};
    unordered_set<string> s(dict.begin(), dict.end());
    vector<int> dp(str.size()+1,-1);
    cout << solve(str, s,dp);
    return 0;
}