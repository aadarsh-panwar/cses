#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
//https://www.techiedelight.com/find-smallest-missing-element-sorted-array/
int missing_number(vector<int> &v) {
    if(v[0] != 0)
    return 0;
    int l = 0, r = v.size()-1;
    while(l < r) {
        int mid = (l+r)/2;
        if(mid == v[mid]) {
            l = mid+1;
        }
        else 
        r = mid-1;
    }
    return v[l]+1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {0, 1, 2, 3, 4, 5, 6};
    cout << missing_number(v);
    return 0;
}