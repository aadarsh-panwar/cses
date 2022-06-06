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
    int n, x;
    cin >> n >> x;
    multiset<int> dist{n};
    set<int> lights{0, n};
    for(int i =0;i<x;++i) {
        int p;
        cin >> p;
        auto it = lights.upper_bound(p);
        auto it2 = it;
        --it2;
        lights.insert(p);
        dist.erase(dist.find((*it) - (*it2)));
        dist.insert(p - (*it2));
        dist.insert((*it) - p);
        auto ans = dist.end();
        --ans;
        cout << (*ans) << " ";
    }
    return 0;
}