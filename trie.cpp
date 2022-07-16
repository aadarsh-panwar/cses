#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <map>

using namespace std;

class TrieNode {
    public :
    bool isLeaf;
    map<char,TrieNode*> map;
}; 


void insert(TrieNode* &root, const string &word) {
    if(root == nullptr) {
        root = new TrieNode();
    }
    TrieNode *cur = root;
    for(auto it: word) {
        if(cur->map.find(it) == cur->map.end())
        cur->map[it] = new TrieNode;
        cur = cur->map[it];
    }
    cur->isLeaf = true;
}

bool search(TrieNode *&root, const string &word) {
    if(root == nullptr)
    return false;
    TrieNode *cur = root;
    for(auto it: word) {
        if(cur->map.find(it) == cur->map.end())
        return false;
        cur = cur->map[it];
    }
    return cur->isLeaf;
}

void traverse(TrieNode *root, string word) {
    if(root == nullptr)
    return;
    if(root->isLeaf) {
        cout << word << endl;
    }
    for(auto it : root->map) {
        traverse(it.second, word + it.first);
    }
}

void searchUtil(TrieNode *&cur, string prefix, vector<string>&words) {
    if(cur == nullptr)
    return;
    if(cur->isLeaf) {
        words.push_back(prefix);
    }
    if(words.size() ==3)
    return;
    for(auto it: cur->map) {
        searchUtil(it.second, prefix + it.first, words);
    }
}

vector<string> searchPrefix(TrieNode * &root, const string &prefix) {
    TrieNode* cur = root;
    for(auto it: prefix) {
        cur = cur->map[it];
    }
    vector<string> words;
    searchUtil(cur, prefix, words);
    return words;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<string> words= {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord  = "mouse";
    TrieNode *root =nullptr;
    for(auto w: words) {
        insert(root, w);
    }
    vector<vector<string>> res(searchWord.size());
    for(int i=0;i<searchWord.size();++i) {
        res[i] = searchPrefix(root,searchWord.substr(0,i+1));
    }
    for(auto it: res) {
        for(auto w: it) {
            cout << w << " ";
        }
        cout <<endl;
    }
    return 0;
}