#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
typedef vector<vector<int>> vvi;



void printAllPath(vvi & mat,vector<int> &path,  int r, int c, int m, int n) {
    if(r < 0 || r >= m || c < 0 || c >= n)
    return;
    path.push_back(mat[r][c]);
    if(r == m-1 && c == n-1){
        for(auto it: path) {
            cout << it <<" ";
        }
        cout << endl;
        path.pop_back();
        return;
    }
    printAllPath(mat, path, r+1, c, m, n);
    printAllPath(mat, path, r, c+1, m,n);
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vvi mat = {{1,  2,  3 },
            { 4 , 5 , 6 },
            { 7 , 8,  9 }};
    vector<int> path;
    printAllPath(mat, path, 0, 0, mat.size(), mat[0].size());
    return 0;
}