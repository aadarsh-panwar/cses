#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {10, 4, 2, 5, 6, 3, 8, 1};
    int k = 3;
    int mn = v.size();
    int sum = 0;
    for(int s = 0, e = 0;e < v.size();++e) {
        if(e - s +1 < k) {
            sum += v[e];
        }
        else {
            while(e - s +1 > k) {
                sum -= v[s];
                mn = min(mn, sum);
                ++s;

            }
        }
    }
    return 0;
}