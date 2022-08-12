#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
//https://cses.fi/problemset/task/1082

const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >>n;
    int total = 0;
    for(int i = 1;i<=n;++i) {
        int sum =1;
        for(int j = 2;j*j<=i;++j) {
            int cnt = 0;
            while(i%j ==0){
                i /= j;
                ++cnt;
            }
            sum *= (pow(j, cnt) - 1)/(j -1);
            sum %= mod;
        }
        if(i > 1) {
            
        }
        total += sum;
        total %= mod;
    }
    cout << total;
    return 0;
}