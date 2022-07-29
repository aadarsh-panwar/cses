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

    void dividable() {
        queue<int> q;
        bool flag = true;
        vector<int> team(v+1, -1);
        for(int i = 1;i<=v;++i) {
        if(team[i] != -1)
        continue;
        q.push(i);
        while(!q.empty()) {
            int u =q.front();
            q.pop();
            if(team[u]== -1)
            team[u] = 0;
            for(auto it= adj[u].begin();it!= adj[u].end();++it) {
                if(team[*it] == team[u]) {
                    flag = false;
                    break;
                }
                else if(team[*it] == -1){
                    team[*it] = !team[u];
                    q.push(*it);
                }
            }
            if(!flag) 
            break;
        }
        }
        if(!flag) {
            cout << "IMPOSSIBLE" <<endl;
        }
        else {
            for(int i = 1;i<=v;++i) {
                cout << team[i]+1 << " ";
            }
        }
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
    g.dividable();
    return 0;
}