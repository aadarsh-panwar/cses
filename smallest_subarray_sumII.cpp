#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <climits>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, t;
    cin >> n >>t;
    vector<int> v(n);
    for(int i=0;i<n;++i) {
        cin >> v[i];
    }
    long long int cnt = 0;
    map<long long, int> freq;
    freq[0] = 1;
    long long sum =0;
    for(int i =0;i<n;++i) {
        sum += v[i];
        cnt += freq[sum -t];
        freq[sum]++;
    }
    cout << cnt;
    return 0;
}