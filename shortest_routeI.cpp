#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
typedef pair<long, long> pii;
class graph  {
    public : 
    vector<vector<pii>> adj;
    long v;
    graph(long v) {
        this-> v= v;
        adj.resize(v+1);
    }

    void addEdge(long u, long v,long wt) {
        adj[u].push_back({v, wt});
    }

    void shortest_distance(long src) {
        vector<long> dist(v+1, LONG_MAX);
        dist[src] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            long u = pq.top().second;
            pq.pop();
            for(auto it = adj[u].begin(); it!= adj[u].end();++it) {
                long v= it->first;
                long wt = it->second;
                if(dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                } 
            }
        }

        for(long i = 1;i<=v;++i) {
            cout << dist[i] << " ";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long n, m;
    cin >> n >> m;
    graph g(n);
    for(long i = 0;i<m;++i) {
        long u, v, wt;
        cin >> u >> v >> wt;
        g.addEdge(u,v,wt);
    }
    g.shortest_distance(1);
    
    return 0;
}