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
    multiset<int> s;
    for(int i =0;i<n;++i) {
        int a;
        cin >> a;
        auto it= s.upper_bound(a);
        if(it == s.end()) {
            s.insert(a);
        } 
        else {
            s.erase(it);
            s.insert(a);
        }
    }
    cout << s.size();
    return 0;
}