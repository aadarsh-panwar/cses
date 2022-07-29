#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
typedef vector<vector<int>> vvi;

void print(vvi &mat, int m, int n) {
    int rs = 0, cs = 0, re = m, ce = n;
    while(rs < re && cs < ce) {
    for(int i = cs;i<ce;++i) {
        cout << mat[rs][i] << " ";
    }
    for(int i =rs;i<re;++i) {
        cout << mat[i][ce] <<" ";
    }
    for(int i = ce;i> cs;--i) {
        cout << mat[re][i] << " ";
    }
    for(int i = re;i> rs;--i) {
        cout << mat[i][cs] << " ";
    }
    ++rs;
    ++ce;
    --re;
    --ce;
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<vector<int>> mat = {
    {1,2,3,4}
    ,{5,6,8,9}
    ,{10,11,12,13}
    ,{14,15,16,17}};
    print(mat, mat.size()-1, mat[0].size()-1);
    return 0;
}