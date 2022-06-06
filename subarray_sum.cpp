#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long n; 
    cin >> n;
    vector<long> v(n);
    for(long i = 0;i<n;++i) {
        cin >> v[i];
    }
    long max_so_far = LONG_MIN;
    long max_here = 0;
    for(long i =0;i<v.size();++i) {
        max_here = max(v[i], max_here+ v[i]);
        max_so_far = max(max_so_far,  max_here);
    }
    cout << max_so_far;
    return 0;
}