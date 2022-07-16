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
    vector<int> v = {1, 0, 1, 0, 1, 1};
    int one  =0;
    for(auto it: v) {
        if(it == 1)
        ++one;
    }
    int sw = 0;
    int cnt = 0;
    for(int i = 0;i<v.size();++i) {
        if(i >= one) {
            if(v[i -one] == 1)
            --cnt;
        }
        if(v[i] == 1)
        ++cnt;
        sw = max(sw, cnt);
    }
    cout << one - sw;
    return 0;
}