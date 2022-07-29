#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int search(vector<int> &v, int val) {
    int start = 0, end = v.size() -1;
    while(start < end ) {
        int mid = (end - start)/2 + start;
        if(val <= v[mid]) {
            end = mid;
        }
        else 
        start = mid +1;
    }
    if(start == v.size()-1 && v[start] < val) 
    ++start;
    return start;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {10, 12, 15, 17, 18, 20, 25};
    int target = 25;
    int k =4;
    int idx  = search(v,target);
    int i = idx, j= idx;
    int n = v.size()-1;
    int cnt = 1;
    while(i > 0 && j < n && cnt < k) {
        if(abs(v[i-1] - target) > abs(v[j+1] - target)) {
            ++j;
        }
        else {
            --i;
        }
        ++cnt;
    }
    while(i > 0 && cnt < k) {
        --i;
        ++cnt;
    }
    while(j < n && cnt < k) {
        ++j;
        ++cnt;
    }
    cout << i << " "<< j << endl;
    for(int iter = i;iter <= j;++iter) {
        cout << v[iter] <<" " ;
    }
    return 0;
}