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
    string str = "abcbdbdbbdcdabd";
    int k = 2;
    int begin =0, end = 0;

    unordered_map<char,int> freq;
    unordered_set<char> window;
    for(int low = 0, high = 0; high< str.size();++high) {
        window.insert(str[high]);
        freq[str[high]]++;
        while(window.size() > k) {
            if(--freq[str[low]] == 0) {
                window.erase(str[low]);
            }
            ++low;
        }
        if(end - begin < high - low) {
            end = high;
            begin = low;
        }
    }
    cout << begin << " " << end << " "<<end - begin << endl;
    cout << str.substr(begin, end);
    return 0;
}