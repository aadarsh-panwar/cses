#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> prefix(n,0);
    long long psum = 0;
    prefix[0] =1;
    for(int i =0;i<n;++i) {
        int num;
        cin >>num;
        psum += num;
        ++prefix[(psum%n + n)%n];
    }

    long long ans =0;
    for(auto it: prefix) {
        ans += it*(it-1)/2;
    }
    cout << ans;
    return 0;
}