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

lli bin_pow(lli a, lli b, lli c) {
    a %= c;
    if(b == 0)
    return 1;
    lli res = 1;
    while(b > 0) {
        if(b%2 != 0)
        res = res*a%c;
        a = a*a%c;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout << bin_pow(2 ,5,13);
    return 0;
}