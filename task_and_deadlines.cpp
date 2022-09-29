#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
typedef long long int lli ;
//https://cses.fi/problemset/task/1630
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    lli n;
    cin >> n;
    vector<lli> deadline(n), duration(n);
    for(lli i =0;i<n;++i) {
        cin >> duration[i] >> deadline[i];
    }
    vector<lli> prefix(n);
    sort(duration.begin(), duration.end());
    prefix[0] = duration[0];
    for(lli i= 1;i<duration.size();++i) {
        prefix[i] = prefix[i-1] + duration[i];
    }
    sort(deadline.begin(), deadline.end(), greater<lli>());
    lli reward = 0;
    for(lli i= 0;i<n;++i) {
        reward += deadline[i] - prefix[i];
    }
    cout << reward;


    return 0;
}