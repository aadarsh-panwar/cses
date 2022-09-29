#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;++i) {
        cin >> v[i];
    }
    map<int,int> freq;
    int d= 0;
    long long ans = 0;
    int j =0;
    for(int i =0;i<n;++i) {
        while(j <n && (freq.size() < k || freq.count(v[j]) > 0)) {
            ++freq[v[j]];
            ++j;
        }
        ans += j -i;
        if(--freq[v[i]] ==0)
        freq.erase(v[i]);
    }
    cout << ans;
    return 0;
}