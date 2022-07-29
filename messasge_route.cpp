#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class graph {
    public : 
    int v;
    vector<vector<int>> adj;

    graph(int v) {
        this->v = v;
        adj.resize(v+1);
    }

    void addEdge(int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bfs(int dest) {
        int src  = 1;
        queue<int> q;
        q.push(src);
        vector<bool> visited(v+1, false);
        vector<int> path(v+1,-1);
        visited[src] = true;
        bool found= false;
        while(!q.empty()) {
            int u =q.front();
            q.pop();
            if(u == dest) {
                found = true;
            }
            if(found)
            break;
            for(auto it= adj[u].begin();it!= adj[u].end();++it) {
                if(!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                    path[*it] = u;
                }
            }
        }
        if(found) {
            vector<int> p;
            int t = dest;
            p.push_back(t);
            while(path[t] != -1) {
                p.push_back(path[t]);
                t = path[t];
            }
            
            reverse(p.begin(), p.end());
            cout << p.size() << endl;
            for(auto it: p) {
                cout << it << " ";
            }
            cout << endl;
        }
        else
        cout << "IMPOSSIBLE" <<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >>n >> m;
    graph g(n);
    for(int i = 0;i<m;++i) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a,b);
    }
    g.bfs(n);
    return 0;
}