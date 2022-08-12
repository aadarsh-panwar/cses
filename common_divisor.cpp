#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <climits>
#include <string>
using namespace std;
//https://cses.fi/problemset/task/1081

int solve() {
       int n; 
    cin >>n;
    vector<int> v(n);
    for(int i= 0;i<n;++i) {
        cin >>v[i];
    }
    int mx = *max_element(v.begin(), v.end());
    vector<int> freq(mx+1, 0);
    for(auto it: v) {
        ++freq[it];
    }
    for(int i = mx; i>= 1;--i) {
        int j = i;
        int count = 0;
        while(j <= mx) {
            if(freq[j] >=2)
            return j;
            if(freq[j] ==1)
            ++count;
            j += i;
            if(count ==2)
            return i;
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout << solve();
    return 0;
}