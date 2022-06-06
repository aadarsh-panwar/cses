#include <iostream>

#include <vector>
using namespace std;

int binary_search(vector<int> &v, int val) {
    int l = 0, r = v.size()-1;
    while(l <= r) {
        int m = (r-l)/2 + l;
        if(v[m] == val) 
        return m;

        if(v[m] > val) 
        r = m-1;
        else 
        l = m+1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<int> v = {2, 3, 4, 10, 40 };
    cout << binary_search(v,50 );
    return 0;
}