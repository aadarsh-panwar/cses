#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
//https://cses.fi/problemset/task/1083
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >>n;
    int num =0;
    for(int i=0;i<n-1;++i) {
        int a;
        cin >> a;
        num ^= a;
    }
    for(int i =1;i<=n;++i) {
        num ^=i;
    }
    cout << num;
    return 0;
}