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


void shortest_path(vector<vector<long>> &dist, vector<pii> &query, long v) {
        for(long k =1;k<=v;++k) {
            for(long i = 1;i<=v;++i) {
                for(long k =1;k<=v;++k) {
                    if(dist[i]])
                }
            }
        }

        for(auto it: query) {
            if(dist[it.first][it.second] != LONG_MAX)
            cout << dist[it.first][it.second] << endl;
            else
            cout << -1 << endl;
        }
    }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long n,m,q;
    cin >> n >>m >> q;
    vector<vector<long>> dist(n+1, vector<long>(n+1,LONG_MAX));
    for(long i = 1;i<=n;++i) {
        dist[i][i] = 0;
    }
    for(long i =0;i<m;++i) {
        long u,v,wt;
        cin >> u >> v >> wt;
        dist[u][v] = wt;
        dist[v][u] = wt;
    }
    vector<pii> query(q);
    for(long i= 0;i<q;++i) {
        long u,v;
        cin >> u >> v;
        query[i] = {u,v};
    }
    shortest_path(dist,query, n);
    return 0;
}