#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    multiset<int, greater<int>> t;
    cin >> n >> m;
    for(int i =0;i<n;++i) {
        int k;
        cin >> k;
        t.insert(k);
    }
    for(int i =0;i<m;++i) {
        int p;
        cin >> p;
        auto it = t.lower_bound(p);
        if(it == t.end()) {
            cout << "-1" << "\n";
        }
        else {
            cout << (*it);
        cout << "\n";
        t.erase(it);
        }
        
    }
    return 0;
}