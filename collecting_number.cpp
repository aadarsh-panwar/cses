#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    vector<int> v(n);
    for(int i =0;i<n;++i) {
        int num;
        cin >> num;
        m[num] = i;
        v[i] =num;
    }
    for (int i =0;i<x;++i) {
        int a, b;
        cin >> a >> b;
        swap(v[a-1], v[b-1]);
        swap(m[v[a-1]], m[v[b-1]]);
        int round = 0;
    for(auto it = m.begin();it != m.end();) {
        int idx = it->second;
        ++it;
        while(it != m.end() && it->second > idx) {
            idx = it->second;
            ++it;
        }
        ++round;
    }
    cout << round << "\n"; 
    }
    
    return 0;
}