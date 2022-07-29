#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <string>
using namespace std;

class graph {
    public : 
    int v;
    vector<vector<int>> adj;
    graph(int v) {
        this->v = v;
        adj.resize(v+1);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfs(int s, vector<bool> &visited, int parent, vector<int> &path) {
        visited[s] = true;
        path.push_back(s);
        for(auto it = adj[s].begin(); it!= adj[s].end();++it) {
            if(!visited[*it]) {
                if(dfs(*it, visited, s, path) && path.size() > 2)
                return true;
            }
            else if(*it != parent && path.size() > 2) {
                path.push_back(*it);
                return true;
            }
        }
        path.pop_back();
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin >>n >> m;
    graph g(n);
    for(int i = 0;i<m;++i) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a,b);
    }
    
    vector<int> path;
    bool cycle = false;
    vector<bool> visited(n+1,false);
    for(int i = 1;i<=n;++i) {
        if(!visited[i])
        cycle = g.dfs(i, visited, -1, path);
        if(cycle)
        break;
    }
    if(cycle) {
        int i =0;
        int end =path[path.size()-1];
        while(i < path.size() && path[i] != end)
        ++i;
        cout << path.size() - i <<endl;
        while(i < path.size()) {
            cout << path[i] << " ";
            ++i;
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}