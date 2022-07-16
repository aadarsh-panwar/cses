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
    string str = "XYYZXZYZXXYZ";
    vector<int> freq(256, 0);
    string pat = "XYZ";
    multiset<char> set(pat.begin(), pat.end());
    multiset<char> window;
    for(int i =0;i<str.size();++i){
        if(i < pat.size()) 
        window.insert(str[i]);
        else {
            if(window == set) {
                cout << i - pat.size() <<" ";
            }
            auto it = window.find(str[i - pat.size()]);
            if(it != window.end())
            window.erase(it);
            window.insert(str[i]);
        }
    }
    if(window == set) {
        cout << str.size() - pat.size() << endl;
    }
    return 0;
}