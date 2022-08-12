#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
//https://atcoder.jp/contests/abc169/tasks/abc169_d
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long n = 997764507000;
    long total = 0;
    for(long i = 2;i*i<= n;++i) {
        long cnt = 0;
        while(n%i== 0) {
            ++cnt;
            n /= i;
        }
        int j = 1;
        while(cnt - j >= 0) {
            ++total;
            cnt -= j;
            ++j;
        }
    } 
    if(n > 0 && n != 1) 
    ++total;
    cout << total ;
    return 0;
}