#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
//https://cses.fi/problemset/task/1069
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string str;
    cin >> str;
    int mx = 1;
    for(int i =0;i<str.size();) {
        int j =i+1;
        while(j < str.size() && str[i] == str[j]){
            ++j;
        }
        mx = max(mx, j -i);
        i =j;
    }
    cout << mx;
    return 0;
}