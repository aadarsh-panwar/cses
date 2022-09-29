#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
//https://cses.fi/problemset/task/1070
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n == 2 || n == 3) {
        cout << "NO SOLUTION";
    }
    else {
        for(int i =2;i<=n;i+=2){
            cout << i << " ";
        }
        for(int i =1;i<=n;i+=2){
            cout <<i << " ";
        }
    }
    return 0;
}