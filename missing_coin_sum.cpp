#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

long solve(vector<int> &v) {
    sort(v.begin(), v.end());
    long res = 1;
    for(int i =0;i<v.size() && v[i] <= res;++i) {
        res = res + v[i];
    }
    return res;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >>n ;
    vector<int> v(n);
    for(int i=0;i<n;++i) {
        cin >> v[i];
    }
    cout << solve(v);
    return 0;
}