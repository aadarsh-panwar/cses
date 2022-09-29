#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
typedef vector<int> vi;

int median(vi &a, vi &b) {
    int m = a.size(), n = b.size();
    int i = 0, j = 0;
    int m1  = -1, m2 = -1;
    for(int cnt = 0;cnt <= (m+n)/2;++cnt) {
        m2 = m1;
        if(i != m && j != n) {
            m1 = a[i] < b[j]? a[i++]:b[j++];
        }
        else if(i < m) {
            m1 = a[i++];
        }
        else {
            m1 = b[j++];
        }
    }
    if((m+n)%2 ==0) {
        return (m1+m2)/2;
    }
    return m1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v1 = {900};
    vector<int> v2 = {5,8,10,20};
    cout << median(v1, v2);

    return 0;
}