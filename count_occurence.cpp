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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int num = 11;
    int left_pos = occurence(v, num, true);
    int right_pos = occurence(v, num, false);
    if(left_pos != -1 && right_pos != -1)
    cout << (right_pos - left_pos +1);
    else 
    cout << 0;
    return 0;
}