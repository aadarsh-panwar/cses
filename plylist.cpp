#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;++i) {
        cin >> v[i];
    }
    set<int> h;
    int mx = 0;
    for(int i= 0, j = 0;i<n;++i) {
        if(h.find(v[i]) == h.end()) {
            h.insert(v[i]);
            mx = max<int>(mx, h.size());
        }
        else {
            while(h.find(v[j]) != h.end()) {
                h.erase(v[j]);
                ++j;
            }
            h.insert(v[i]);
        }
        cout << mx;
    }
    return 0;
}