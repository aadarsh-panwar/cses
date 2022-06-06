#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int partition(vector<int> &v, int l, int r) {
    int i = l;
    for(int j =l; j<= r-1;++j) {
        if(v[j] <= v[r]) {
            swap(v[i], v[j]);
            ++i;
        }
    }
    swap(v[i], v[r]);
    return i;
}

void quick_sort(vector<int> &v, int l, int r) {
    if(l >= r) 
    return ;
    int part = partition(v, l, r);
    quick_sort(v, l, part-1);
    quick_sort(v, part+1, r);
}   

int find_index(vector<int> &v, int l, int r) {
    int idx = l;
    int val = v[l]+l;
    for(int i = l+1;i<=r;++i) {
        if(v[i] + i > val) {
            idx = i;
            val = v[i] +i;
        }
    }
    return idx;
}

int min_jump_to_reach_end(vector<int> &v) {
    int jump = 0;
    int r = v.size()-1;
    for(int i = 0;i<=r;) {
        if(v[i] == 0 && i != r)
        return -1;
        int s = i+1;
        int e = i+ v[i];
        if(e >= r)
        return ++jump;
        i = find_index(v, s,e);
        ++jump;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n = 7;
    for(int i =0;i<8;++i) {
        cout << (((1 << i) &n) >> i) << " ";
    }
    return 0;
}