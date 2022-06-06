#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,x;
    cin>> n >> x;
    vector<int> c(n);
    vector<bool> g(n);
    for(int i=0;i<n;++i) {
        cin>> c[i];
    }
    sort(c.begin(), c.end());
    int cnt = 0;
    int i= 0;
    int j= c.size()-1;
    while(i < j) {
        if(c[i] + c[j] > x)  {
            --j;
        }
        else {
            ++cnt;
            g[i] = g[j] = true;
            ++i;
            --j;
        }
    }
    for(int i =0;i<g.size();++i) {
        cnt += g[i] == false;
    }
    cout << cnt;
    return 0;
}