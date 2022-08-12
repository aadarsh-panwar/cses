#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

class TrieNode {
    public : 
    bool isLeaf;
    unordered_map<char,TrieNode*> map;
    TrieNode() {
        isLeaf =false;
    }
};

void insert(TrieNode *&root, const string &word) {
    if(root == nullptr) {
        root = new TrieNode();
    }
    TrieNode *cur = root;
    for(auto it: word) {
        if(cur->map.find(it) == cur->map.end())
        cur->map[it] = new TrieNode();
        cur = cur->map[it];
    }
    cur->isLeaf = true;
}

string lcp(TrieNode *&root) {
    string prefix = "";
    if(root == nullptr) {
        return prefix;
    }
    TrieNode *cur = root;
    while(cur != nullptr) {
        if(cur->map.size() != 1 || cur->isLeaf) {
            return prefix;
        }
        char c = cur->map.begin()->first;
        prefix += c;
        cur = cur->map[c];
    }
    return prefix;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<string> words = {"abcdef", "abcdef", "abcdefg", "ab", "abc"};
    TrieNode *root = nullptr;
    for(auto word: words) {
        insert(root, word);
    }
    cout << lcp(root);
    return 0;
}