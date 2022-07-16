#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

// {
//     {1,2,3,4,5},
//     {1,2,3,4,5},
//     {1,2,3,4,5},
//     {1,2,3,4,5},
//     {1,2,3,4,5}
// }

// B = {
//     {1,2,3},
//     {1,2,3},
//     {1,2,3},
// }

typedef vector<vector<int>> vvi;
int matrix_mulit(vvi &a, vvi &b, int i, int j) {

}

int main() {
    
    vector<vector<int>> a = {{1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5}};


    vector<vector<int>> b = {{1,2,3},
    {1,2,3},
    {1,2,3},};
    int row = 0;
    int col= 0;
    vector<vector<int>> res(b.size(),vector<int>(b[0].size(), 0));
    int rowEnd = a[0].size() - b[0].size()+1;
    int colEnd = a.size() - b.size();
    for(int i =0; i < rowEnd; ++i) {
        for(int j =0;j< colEnd;++j) {
           int res =  matrix_multi(a, b, i, j);
        }
    }

    
    return 0;
}