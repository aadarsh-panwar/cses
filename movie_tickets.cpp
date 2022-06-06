#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef std::pair<long, long> pii;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long n;
    cin >>n;
    vector<pair<long, long>> v(n);
    for(long i =0;i<n;++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](const pii &a, const pii  &b) ->bool {
        return a.second < b.second;
    });
    long mx = 0;
    int lastEnd = -1;
    for(long i=0;i<v.size();++i) {
        if(v[i].first >= lastEnd) {
            lastEnd = v[i].second;
            ++mx;
        }
    }
    cout << mx;
    return 0;
}