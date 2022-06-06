#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

void dfs(vector<string> &g, vector<vector<bool>> &visited) {
    
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i =0;i<n;++i) {
        cin >> g[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, 0));

    return 0;
}