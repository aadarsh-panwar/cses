#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string str = "ddddd";
    int mx= 0;
    for(int i = 0,j = i+1; i < str.size();++i) {
        while(j < str.size() && str[i] == str[j]) {
            mx = max(j - i+1, mx);
            ++j;
        }
        
        j= i;
    }
    cout << mx;
    return 0;
}