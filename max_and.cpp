#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int checkBit(int pattern, vector<int>& v) {
    int count = 0;
    for(auto it: v) {
        if((pattern &it) == pattern) 
        ++count;
    }
    return count;
}

int max_and(vector<int> &v) {
    int count;
    int res = 0;
    for(int bit = 31;bit >= 0;--bit) {
        count = checkBit((res | (1 <<bit)),v);
        if(count >= 2) {
            res = res | (1 << bit);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {4, 8, 6, 2};
    cout << max_and(v);
    return 0;
}