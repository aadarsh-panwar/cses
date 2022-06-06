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
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int mid = v[n/2];
    long cost = 0;
    for(int i = 0;i<n;++i) {
        cost += abs(v[i] - mid);
    }
    cout << cost;
    return 0;
}