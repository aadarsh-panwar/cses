#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >>n;
    for(int i = 0;i<n;++i) {
        int num;
        cin >>num;
        int total = 1;
        for(int j = 2;j*j<= num;++j) {
            int cnt = 0;
            while(num%j ==0) {
                ++cnt;
                num /= j;
            }
            total = (cnt+1)*total;
        }
        if(num > 1){
            total *= 2;
        }
        cout << total <<endl;
    }
    return 0;
}