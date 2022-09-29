#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
typedef long long int lli;
//https://cses.fi/problemset/task/1620
bool check(vector<lli> &cap, lli sec, lli t) {
    for(lli i = 0;i<cap.size();++i) {
        t -= sec/cap[i];
        if(t <= 0)
        return true;
    }
    return t <= 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    lli n, t;
    cin >>n >> t;
    vector<lli> cap(n);
    for(lli i =0;i<n;++i) {
        cin >> cap[i];
    }
    lli s = 1, e = 1e18;
    lli ans = e;
    while(s <= e) {
        lli mid  = (s +e)/2;
        if(check(cap, mid, t)) {
            ans =mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    cout << ans;
    return 0;
}