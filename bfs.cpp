#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;


class graph {
    public : 
    int v;
    vector<vector<int>> adj;

    graph(int v) {
        this->v = v;
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void bfs(int s) {
        vector<bool> visited(v);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(auto it = adj[u].begin(); it != adj[u].end();++it) {
                if(!visited[*it]) {
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
        cout << endl;
    }

    void print() {
        for(int i =0;i<v;++i) {
            cout << i << ":";
            for(auto it = adj[i].begin();it != adj[i].end();++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    void dfs(int u, vector<bool> &visited) {
        stack<int> s;
        s.push(u);
        while(!s.empty()) {
            int u = s.top();
            s.pop();
            visited[u] = true;
            for(auto it = adj[u].begin();it != adj[u].end();++it) {
                if(!visited[*it]) 
                s.push(*it);
            }
        }
    }

    bool strongly_connected() {
        vector<bool> visited(v);
        int start = 0;
        dfs(start,visited);
        if(find(visited.begin(), visited.end(), false) != visited.end())
        return false;
        visited.assign(v, false);
        graph rev(v);
        for(int i =0;i<v;++i) {
            for(auto it = adj[i].begin();it != adj[i].end();++it) {
                rev.addEdge(*it, i);
            }
        }
        rev.dfs(start, visited);
        if(find(visited.begin(), visited.end(), false) != visited.end())
        return false;
        return true;
    }

    void topological_sort() {
        stack<int> s;
        vector<bool> visited(v);
        for(int i= 0;i<v;++i) {
            if(!visited[i])
            topological_sort_util(i, visited, s);
        }
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }

    void topological_sort_util(int u, vector<bool> &visited, stack<int> &s) {
        visited[u] = true;
        for(auto it = adj[u].begin(); it != adj[u].end();++it) {
            if(!visited[*it]) {
                topological_sort_util(*it, visited, s);
            }
        }
        s.push(u);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n= 6;
    vector<pair<int,int>> edges = {
       {5,2},{5,0},{4,0},{4,1},{2,3},{3,1}
    };
    graph g(n);
    for(auto it : edges) {
        g.addEdge(it.first, it.second);
    }
    g.print();
    cout << "-------" << endl;
    g.topological_sort();

    return 0;
}