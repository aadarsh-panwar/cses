#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
typedef vector<int> vi;
int max_and(vi &v) {
    int res = 0;
    int ans = 0;
    for(int i = 31;i>= 0;--i) {
        res = ans | (1 << i);
        int cnt = 0;
        for(auto it : v) {
            if((it&res) == res)
            ++cnt;
        }
        if(cnt >= 2)
        ans += (1 << i);
    }
    return ans;
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {16,4,8,2,4};
    cout << max_and(v);
    return 0;
}