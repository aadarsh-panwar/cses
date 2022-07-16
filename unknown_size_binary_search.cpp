#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int getValue(vector<int> &v, int k ) {
    if(k >= v.size()) 
    return INT_MAX;
    return v[k];
}

int search_value(vector<int> &v, int start, int end, int val) {
    int s= start, e = end;
    while(s <= e) {
        int mid = (e - s) + s/2;
        int midValue = getValue(v, mid);
        if(midValue == INT_MAX || midValue > val)
        e = mid-1;
        else if(midValue == val)
        return mid;
        else 
        s = mid+1;
    }
    return -1;
}

int find_range(vector<int> &v, int val) {
    int s = 0, e = 0,i= 0;
    while(1) {
        s = e;
        int jump = pow(2, i);
        ++i;
        e =  s+ jump;
        int st = getValue(v, s);
        int et = getValue(v, e);
        if(val > et)
        continue;
        else {
            cout << s << " " << e << endl;
           // return search_value(v, s, e, val);
           for(int j = s;j<= e;++j) {
               if(getValue(v, j) != INT_MAX && getValue(v,j) == val)
               return j;
           }
           return -1;
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v ={-1,0,3,5,9,12};
    cout << find_range(v, 9);
    return 0;
}