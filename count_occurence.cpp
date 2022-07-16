#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
//https://www.techiedelight.com/count-occurrences-number-sorted-array-duplicates/
using namespace std;

int occurence(vector<int> &v, int num, bool left) {
    int l = 0, r = v.size()-1;
    int pos = -1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(v[mid]== num) {
            pos = mid;
            if(left)
            r = mid-1;
            else 
            l = mid+1;
        }
        else if(v[mid] < num) {
            l = mid+1;
        }
        else 
        r = mid-1;
    }
    return pos;
}
void print(vector<int> &v) {
    for(auto it: v)
    cout << it <<" ";
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {3, 4, 5};
    auto it = upper_bound(v.begin(), v.end(),3);
    if(it != v.end())
    cout << *it << endl;
    else 
    cout << "end" << endl;
    print(v);
    *it = 1;
    print(v);
    it = upper_bound(v.begin(), v.end(),1);
    if(it != v.end())
    cout << *it << endl;
    else 
    cout << "end" << endl;
    return 0;
}