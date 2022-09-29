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
    int n, k;
    cin >>n>> k;
    vector<int> v(n);
    for(int i =0;i<n;++i) {
        cin >> v[i];
    }
    vector<int> subv(k);
    for(int i=0;i<k;++i) {
        subv[i] = v[i];
    }
    sort(subv.begin(), subv.end());
    multiset<int> l,r;
    for(int i =0;i<k;++i) {
        if(i < (k/2 +1))
        l.insert(subv[i]);
        else 
        r.insert(subv[i]);
    }
    cout << (*l.rbegin()) << " ";
    
    for(int i =k;i<n;++i) {
        int prev = v[i-k];
        if(l.count(prev) > 0){
            l.erase(prev);
        }
        else {
            r.erase(prev);
        }
        while(l.size() < k/2 + k%2) {
            auto it = r.begin();
            l.insert(*it);
            r.erase(*it);
        }
        while(l.size() > k/2 + k%2) {
            auto it = l.rbegin();
            r.insert(*it);
            l.erase(*it);
        }
        cout << (*l.rbegin()) << " ";
    }

    return 0;
}