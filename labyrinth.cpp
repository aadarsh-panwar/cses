#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

class Node {
    public :
    int r, c;
    char d;
};

class graph {
    public :
    int v;
    vector<string> adj;
    graph(int v) {
        this->v = v;
        adj.resize(v);
    }

    void bfs() {
        int n = this->v;
        int m = adj[0].size();
        Node start, end;
        for(int i= 0;i<n;++i) {
            for(int j = 0;j<m;++j) {
                if(adj[i][j] == 'A') 
                start.r = i, start.c = j;
                else if(adj[i][j] == 'B') 
                end.r = i, end.c = j;
            }
        }
        queue<Node> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        q.push(start);
        unordered_map<Node, Node> map;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        vector<char> dir = {'U','D', 'L', 'R'};
        visited[start.r][start.c] = true;
        map[{start.r, start.c, 'a'}] = {-1, -1, 'a'};
        while(!q.empty()) {
            Node u = q.front();
            q.pop();
            if(u.r == end.r && u.c == end.c) {
                break;
            }
            for(int i = 0;i<4;++i) {
                int x = u.r + dx[i];
                int y = u.c + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == false
                && adj[x][y] != '#') {
                    q.push({x,y,dir[i]});
                    map[{x,y,dir[i]}] = {u.r,u.c, dir[i]};
                    visited[x][y] = true;
                }
            }
        }

    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin >>n >> m;
    graph g(n);
    for(int i = 0;i<m;++i) {
        cin >> g.adj[i];
    }
    g.bfs();
    return 0;
}