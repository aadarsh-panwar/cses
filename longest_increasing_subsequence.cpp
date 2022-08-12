#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
typedef vector<int> vi;
int lis(vi &v) {
   vector<int> dp(v.size(), 1);
   for(int i =0;i<v.size();++i) {
       for(int j = 0;j<i;++j){
           if(v[j] < v[i] && dp[j] + 1 > dp[i])
           dp[i] = dp[j]+1;
       }
   }
   return *max_element(dp.begin(), dp.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    cout << lis(v);
    return 0;
}