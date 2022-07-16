#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

void all_combination(vector<int> &v, int n ) {
    if(n == 0) {
        for(auto it: v) {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    for(int i= n;i>= 1;--i) {
        v.push_back(i);
        all_combination(v, n -i);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n = 5;
    vector<int> v;
    all_combination(v, n);
    return 0;
}