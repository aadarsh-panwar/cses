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
    int count;

     TrieNode() {
        isLeaf = 0;
        count =0;
    }
};

void insert(TrieNode *&root, const string &word) {
    if(root == nullptr) {
        root= new TrieNode();
    }
    TrieNode *cur = root;
    for(auto it: word) {
        if(cur->map.find(it) == cur->map.end())
        cur->map[it] =new TrieNode();
        ++cur->count;
        cur = cur->map[it];
    }
    cur->isLeaf = true;
}

void unique_prefix(TrieNode* &root, string word,vector<string> &res) {
    if(root == nullptr) {
        return;
    }
    if(root->count ==1) {
        res.push_back(word);
        return;
    }
    for(auto m : root->map) {
        unique_prefix(m.second, word + m.first, res);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<string> words = {"AND", "BONFIRE", "BOOL", "CASE", "CATCH", "CHAR"};
    TrieNode *root =nullptr;
    for(auto it: words) {
        insert(root, it);
    }
    vector<string> res;
    unique_prefix(root,"", res);
    for(auto it: res) {
        cout << it <<endl;
    }
    return 0;
}