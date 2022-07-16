#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
//https://www.techiedelight.com/count-distinct-elements-every-sub-array-size-k-array/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = { 1, 1, 2, 1, 3 };
    int k = 3;
    set<int> elem;
    unordered_map<int, int> freq;
    for(int i = 0;i<k;++i) {
        elem.insert(v[i]);
        ++freq[v[i]];
    }
    for(int i=k-1;i<v.size();++i) {
        if(i - k > 0 ){
            if(--freq[v[i -k]] == 0)
                elem.erase(v[i-k]);
        }
        elem.insert(v[i]);
        ++freq[v[i]];
        cout << elem.size() << " ";
    }
    return 0;
}