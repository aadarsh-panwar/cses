#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
//https://cses.fi/problemset/task/1094
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i) {
        cin >> v[i];
    }
    long long moves = 0;
    for(int i=0;i<n-1;++i){
        if(v[i] > v[i+1]) {
            moves += (long)v[i] - (long)v[i+1];
            v[i+1] = v[i];
        }
    }
    cout << moves;
    return 0;
}