#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string str = "abcadce";
    int k= 4;
    int dist = 0, cnt = 0;
    unordered_map<char, int> freq;
    for(int s = 0, e = 0;e<str.size();++e) {
        if(++freq[str[e]] ==1) {
            ++dist;
        }
        if(dist > k) {
            while(s < e && dist > k ) {
                if(--freq[str[s]] == 0) 
                --dist;
                ++s;
                if(dist == k) 
                ++cnt;
            }
        }
        if(dist == k) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}