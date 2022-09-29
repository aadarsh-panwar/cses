#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i) {
        cin >> v[i];
    }
    typedef pair<int, int> pi;
    stack<pi> s;
    for(int i=0;i<n;++i) {
        while(!s.empty() && s.top().first >= v[i]) {
            s.pop();
        }
        if(s.empty()) {
            cout << 0 << " ";
            s.push({v[i], i});
        }
        else {
            cout << s.top().second + 1 << " ";
            s.push({v[i],i});
        }
    }

    return 0;
}