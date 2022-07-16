#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    unordered_set<char> set;
    string str = "findlongestsubstring";
    int bg = 0, ed = 0;
    for(int low = 0, end = 0;end <str.size();++end) {
        auto it = set.find(str[end]);
        if(it != set.end()) {
            while(set.find(str[end]) != set.end()) {
                set.erase(str[low]);
                ++low;
            }
            set.insert(str[end]);
        }
        else {
            set.insert(str[end]);
        if(ed - bg < end - low) {
            ed = end;
            bg = low;
        }
        }
        
    }
    cout << str.substr(bg, ed - bg +1) <<endl;
    return 0;
}