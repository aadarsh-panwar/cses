#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int ithBit(int n, int i) {
    return (n>>(i-1))&1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n = 3;
    cout << ithBit(3,1) << endl;
    cout << ithBit(3, 2) << endl;
    cout << ithBit(3, 3) <<endl;
    return 0;
}