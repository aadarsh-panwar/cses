#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

typedef vector<vector<int>> vvi;

bool isSafe(vvi &board, int r, int c, int n){
    int i =r, j =c;
    while(i >= 0) {
        if(board[i][c] == 1)
        return false;
        --i;
    }
    i = r, j = c;
    while(i >= 0 && j >= 0) {
        if(board[i][j] ==1)
        return false;
        --i;
        --j;
    }
    i = r, j = c;
    while(i >= 0 && j < n) {
        if(board[i][j] == 1)
        return false;
        --i;
        ++j;
    }
    return true;
}

void solve(vvi & board, int r, int n) {
  if(r == n) {
      for(auto vec: board) {
          for(auto it: vec) {
              cout << it << " ";
          }
          cout << endl;
      }
      cout << "--------" <<endl;
      return;
  }
  for(int i = 0;i<n;++i) {
      if(isSafe(board, r, i, n)) {
          board[r][i] = 1;
          solve(board,r+1,n);
          board[r][i] = 0;
      }
  }
 
}

int main() {
    int n =4;
    vvi board(n, vector<int>(n, 0));
    solve(board, 0, n);
    return 0;
}