#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;



int main() {
//     Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    vector<string> words = {"eat","tea","tan","ate","nat","bat"};
        unordered_map<string, vector<string>> map;
        for(auto it : words) {
            string word = string(it);
            sort(word.begin(), word.end());
            //map.insert({word, it});
            map[word].push_back(it);
        }
        for(auto it: map){
            for(auto v : it.second) {
                cout << v << " ";
            }
            cout << endl;
        }
        // unordered_map<string, vector<string>> res;
        // for(auto it: map) {
        //     res[it.first].push_back(it.second);
        // }
        // for(auto it: res) {
        //     cout << "key:" << it.first << " ";
        //     for(auto v : it.second) 
        //     cout << v << " ";
        //     cout << endl;
        // }
    return 0;
}