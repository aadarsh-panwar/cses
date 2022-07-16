#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
// abc, bac
int main() {
    string a = "abc", b = "bac";
    // a-> 1, b-> 0, c-> 0, d-> -1
    if(a.size() != b.size())
    {
        cout << "Not anagram";
    }
    else {
        vector<int> freq(26, 0);
        for(int i = 0;i<a.size();++i) {
            freq[a[i] - 'a']++;// a- > 0, b -> 1 
    }
    for(int i =0;i<b.size();++i) {
        freq[b[i]- 'a']--;
    }
    bool valid = true;
    for(auto it: freq) {
        if(it != 0){
            valid = false;
            break;
        }
    }
    if(valid) 
    cout << "Anagram";
    else 
    cout << "Not anagram";
    }
    
    return 0;
}