#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <stack>
using namespace std;
//https://www.techiedelight.com/find-shortest-path-in-maze/

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

class Node {
    public : 
    int x,y,dir;
    Node(int x, int y ) {
        this->x = x;
        this->y = y;
        this->dir = -1;
    }
};
bool isValid(vvi &maze, int x, int y, int n, vvb &visited) {
    if(x >= 0 && y >= 0 && x < n && y < n && maze[x][y] ==1 && visited[x][y] == false)
    return true;
    return false;
}

vector<int> row = {0,0,1,-1};
vector<int> col = {1,-1,0,0};

int shortest_path(vvi & maze, int sx,int sy, int dx, int dy, int n) {
    vvb visited(n, vector<bool>(n, false));
    
    Node start(sx, sy);
    stack<Node> s;
    s.push(start);
    visited[sx][sy] =true;
    int mn = n*n;
    while(!s.empty()) {
        Node u = s.top();
        s.pop();
        visited[u.x][u.y] = false;
        if(u.x == dx && u.y == dy) {
            mn = min<int>(mn, s.size());
        }
        else if(u.dir == 3){
            visited[u.x][u.y] = false;
        }
        else {
            ++u.dir;
            s.push(u);
            visited[u.x][u.y] = true;
            int nx = u.x + row[u.dir];
            int ny = u.y + col[u.dir];
            if(isValid(maze, nx, ny, n, visited)) {
                s.push(Node(nx, ny));
                visited[nx][ny] = true;
            }
        }

    }
    return mn;

}


int pathUtil(vvi &maze, int i, int j,int dx, int dy, int n, vvb &visited){
    if(i == dx && j == dy) {
        cout << i << " " << j << endl;
        return 0;
    }
    int mn = n*n;
    for(int k = 0;k<4;++k) {
        int r = i + row[k];
        int c = j + col[k];
        if(isValid(maze, r, c, n, visited)) {
           visited[r][c] = true;
           mn = min(mn,1+ pathUtil(maze,r,c, dx, dy, n, visited));
           visited[r][c] = false;
        }
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<vector<int>> maze = {{ 1,1,1,1,1,0,0,1,1,1 },
{ 0,1,1,1,1,1,0,1,0,1 },
{ 0,0,1,0,1,1,1,0,0,1 },
{ 1,0,1,1,1,0,1,1,0,1},
{ 0,0,0,1,0,0,0,1,0,1 },
{ 1,0,1,1,1,0,0,1,1,0 },
{0,0,0,0,1,0,0,1,0,1 },
{0,1,1,1,1,1,1,1,0,0 },
{ 1,1,1,1,1,0,0,1,1,1},
{ 0,0,1,0,0,1,1,0,0,1 }};

    cout << shortest_path(maze,0,0,0,1,maze.size());

    return 0;
}