#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    
    vector<int> height = {10,9,8,7,6 };
    int k =3;
    int n = height.size();
    int count = 0;
    for(int i =0;i<n;++i) {
        bool canSee = true;
        for(int j = i+1;j< n && j < i+1+k;++j) {
            if(height[j] >= height[i]) {
                canSee = false;
                break;
            }
        }
        if(canSee)
        ++count;
    }

    cout << count;

    return 0;
}