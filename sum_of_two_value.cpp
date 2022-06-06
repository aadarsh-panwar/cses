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
    unordered_map<int, int> map;
    vector<int> v(n);
    for(int i=0;i<n;++i) {
        if(map.count(x - v[i]) != 0) {
            cout << i+1 << " " <<map[x-v[i]] <<"\n";
            return 0;
        }
        map[v[i]] = i+1;
    }
   
    cout << "IMPOSSIBLE";
    return 0;
}