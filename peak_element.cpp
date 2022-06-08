#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int peak_elment(vector<int> & v) {
    int l = 0, r = v.size() -1;
    int n = v.size()-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(mid > 0 && mid < n && v[mid-1] <= v[mid] && v[mid+1] <= v[mid]) {
            return mid;
        }
        else if(mid == 0 && v[mid +1] <= v[mid])
        return mid;
        else if(mid == n && v[mid-1] <= v[mid])
        return mid;
        else if(mid != 0 && v[mid-1] >= v[mid])
        r = mid-1;
        else 
        l = mid+1;
    }
    return -1;
}

int main() {
    vector<int> v = {4,2,3,5,1};
    int i = peak_elment(v);
    cout << i ;

    return 0;
}