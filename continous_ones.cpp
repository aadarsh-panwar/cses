#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
//https://www.techiedelight.com/find-maximum-length-sequence-continuous-ones-sliding-window/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
    int mx = 0, idx = -1;
    int zero = 0;
    int mx_idx = -1'
    for(int st = 0, ed = 0;ed <v.size() ;++ed) {
        if(v[ed] ==0) {
         ++zero;
         idx = ed;   
        }
        if(zero >1) {
            while(zero > 1){
                if(v[st] == 0)
                --zero;
                ++st;
            }
        }
        else {
            if(v[ed] == 0 && mx < ed - st) {
                idx = ed;
                mx = ed -st;
            }
            else {
                mx = ed - st;
            }
        }
    }
    cout << idx ;
    return 0;
}