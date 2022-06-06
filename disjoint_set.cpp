#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class disjointSet {
    public : 
    int v;
    vector<int> parent;
    vector<int> rank;

     disjointSet(int v) {
        this->v =v;
        parent.resize(v);
        rank.resize(v);
        for(int i  = 0;i<v;++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find_set(int v) {
        if(parent[v] == v)
        return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a != b) {
            if(rank[a] < rank[b]) 
            swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) 
            rank[a]++;  
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    disjointSet s(10);
    cout << s.find_set(2) << endl;
    cout << s.find_set(5) << endl;
    s.union_set(1, 2);
    s.union_set(1,3);
    cout << s.find_set(1) <<endl;
    cout << s.find_set(2) <<endl;
    cout << s.find_set(3) <<endl;
    return 0;
}