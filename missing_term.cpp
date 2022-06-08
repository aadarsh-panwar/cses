#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
//https://www.techiedelight.com/find-missing-term-sequence-ologn-time/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {5, 7, 9, 11, 15};
    int n = v.size();
    int diff = (v[n-1] - v[0])/n;
    int l = 0, r = n-1;
    while(r - l > 1) {
        int mid = (l+r)/2;
        int a = (v[mid] - v[l])/diff;
        int e = mid - l;
        if(a == e)
        l = mid;
        else r = mid;
    }
    cout << v[l] + diff;
    return 0;
}