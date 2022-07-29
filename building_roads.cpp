#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
//https://cses.fi/problemset/task/1666
// building roads (graph)

class graph {
    public :
    int v;
    vector<vector<int>> adj;

    graph(int v) {
        this->v = v;
        adj.resize(v+1);
    }

    void addEdge(int src,int dest){
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    void bfs(int src, vector<bool> &visited) {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto it = adj[u].begin(); it != adj[u].end();++it) {
                if(!visited[*it]) {
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
    }

    void roads() {
        int extraRoads = 0;
        vector<int> roads;
        vector<bool> visited(this->v +1, false);
        for(int i =1;i<=this->v;++i) {
            if(!visited[i]) {
                bfs(i,visited);
                roads.push_back(i);
                ++extraRoads;
            }
        }
        cout << extraRoads-1 << endl;
        for(int i =1;i<extraRoads;++i) {
            cout << roads[i-1] << " " << roads[i] <<endl;
        }

        cout << endl;
        
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for(int i = 0;i<m;++i) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.roads();
    return 0;
}