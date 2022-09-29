#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, t;
    cin >> n >>t;
    vector<int> v(n);
    for(int i=0;i<n;++i) {
        cin >> v[i];
    }
    int cnt = 0;
    int sum = 0;
    int s= 0,e = 0;
    for( s = 0, e =0;e<n;++e) {
        while(s <n && sum >= t) {
            sum -= v[s];
            if(sum == t)
            ++cnt;
            ++s;
        }
        sum += v[e];
        if(sum == t)
        ++cnt;
    }
    while(s < n && sum >= t){
        sum -= v[s];
        if(sum == t)
        ++cnt;
        ++s;
    }
    cout << cnt;
    return 0;
}