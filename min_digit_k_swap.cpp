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
    
    int num = 12345;
    vector<int> digs;
    while(num > 0) {
        digs.push_back(num%10);
        num /= 10;
    }
    reverse(digs.begin(), digs.end());
    int k = 2;
    int i=0;
    while(k > 0) {
        int min = 10;
        int minIdx = -1;
        for(int j = i;j<digs.size();++j){
            if(digs[j] < min) {
                min = digs[j];
                minIdx = j;
            }
        }
        if(minIdx != -1) {
            swap(digs[i], digs[minIdx]);
        }
        --k;
    }
    for(auto it: digs) {
        cout << it;
    }

    return 0;
}