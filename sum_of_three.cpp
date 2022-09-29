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
    int nums, t;
    cin >> nums >> t;
    typedef pair<int, int> pi;
    vector<pi> v(nums);
    for(int i=0;i<nums;++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    bool found = false;
    int l,m,n;
    for(int k =0;k<nums;++k) {
        int c= k;
        int sum = t - v[c].first;
        for(int i =0, j= nums-1;i <j;) {
            if(i == c)
            ++i;
            if(j == c)
            --j;
            if(i >= j)
            break;
            if(v[i].first + v[j].first == sum) {
                found = true;
                l = v[c].second;
                m = v[i].second;
                n = v[j].second;
                break;
            }
            else if(v[i].first + v[j].first < sum)
            ++i;
            else 
            --j;
        }
        if(found)
        break;
    }
    if(found) {
        cout << l+1 << " " << m+1 << " "<< n+1;
    }
    else 
    cout << "IMPOSSIBLE";
    return 0;
}