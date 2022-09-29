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
void update(vi &v, int i, int val) {
    ++i;
    while(i < v.size()) {
        v[i] += val;
        i += i&(-i);
    }
}

int getSum(vi &v, int i) {
    ++i;
    int sum = 0;
    while(i > 0) {
        sum += v[i];
        i -= i&(-i);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> v = {5,5,5,5,5};
    vector<int> tree(v.size()+1, 0);
    for(int i =0;i<v.size();++i) {
        update(tree, i,v[i]);
    }
    cout << getSum(tree, 2) <<endl;
    cout << getSum(tree, 4) <<endl;
    return 0;
}