#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

vector<int> x = {-1,-1,-1,0,0,0,1,1,1};
vector<int> y = {-1,0,1,-1,0,1,-1,0,1};

bool check(vvi &mat, int i, int j,int m, int n, vvb &visited) {
    if(i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == false && mat[i][j] == 1)
    return true;
    return false;
}

void dfsUtil(vvi &mat, int i, int j, int m, int n, vvb &visited) {
    visited[i][j] = true;
    for(int k = 0;k<8;++k) {
        if(check(mat, i+ x[k], j+y[k],m, n, visited)) {
            dfsUtil(mat, i+x[k], j+y[k],m,n, visited);
        }
    }
}



int dfs(vvi & mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int count = 0;
    for(int i =0;i<m;++i) {
        for(int j=0;j<n;++j) {
            if(check(mat, i,j, m, n, visited)) {
                dfsUtil(mat, i, j, m,n, visited);
                ++count;
            }
        }
    }
    return count;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<vector<int>> mat = {
                    {1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}};
    cout << dfs(mat);
    return 0;
}