#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
vector<int> scores = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
int solve(vector<string> &words, vector<int> freq, int idx) {
    if(idx == words.size()) 
    return 0;
    vector<int> v(26, 0);
    for(auto it: words[idx])
    ++v[it - 'a'];
    bool canMake = true;
    for(int i = 0;i<v.size();++i){
        if(v[i] > 0 && freq[i] < v[i]) {
            canMake = false;
            break;
        }
    }
    if(!canMake) {
        return solve(words, freq, idx+1);
    }
    else {
        int s1 = solve(words, freq, idx+1);
        int score = 0;
        for(auto it: words[idx]) {
            --freq[it - 'a'];
            score += scores[it - 'a'];
        }
        int s2 =  score + solve(words, freq, idx+1);
        return max(s1, s2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<string> words = {"leetcode"};
    vector<string> letters = {"l","e","t","c","o","d"};
    
    vector<int> freq(26, 0);
    for(auto it: letters) {
        ++freq[it[0] - 'a'];
    }
    int score = solve(words, freq, 0);
    cout << score;
    return 0;
}