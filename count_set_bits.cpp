#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int set_bits(int n) {
    int cnt = 0;
    while(n) {
        n = n&(n-1);
        ++cnt;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout << set_bits(3) << endl;
    cout << set_bits(10) << endl;
    cout << set_bits(8) << endl;
    return 0;
}