#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i =0;i<n;++i) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mx = 0, c= 0;
    for(int i= 0,j = 0;i < n;) {
        if(a[i] < b[j]) {
            ++c;
            ++i;
        }
        else {
            --c;
            ++j;
        }
        mx =max(mx, c);
    }
    cout << mx;
    return 0;   
}