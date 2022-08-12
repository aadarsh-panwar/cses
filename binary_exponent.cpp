#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

typedef long long int lli;

lli bin_pow(lli a, lli b) {
    if(b == 0)
    return 1;
    lli res = bin_pow(a, b/2);
    if(b&1) 
    return res*res*a;
    return res*res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout << bin_pow(3,9);
    return 0;
}