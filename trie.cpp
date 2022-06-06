#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Trie {
    public : 
    bool isLeaf;
    unordered_map<char, Trie*> map;
    int freq;
};

Trie* getTrieNode() {
    Trie *node =new Trie;
    node->isLeaf = false;
    node->freq = 0;
    return node;
}

void insert(Trie *&head, const string &str) {
    if(head == nullptr) {
        head = getTrieNode();
    }
    Trie *cur = head;
    for(auto it: str) {
        if(cur->map.find(it) == cur->map.end()) {
            cur->map[it] = getTrieNode();
        }
        cur->map[it]->freq++;
        cur = cur->map[it];

    }
    cur->isLeaf = true;
}

bool search(Trie* &head, const string &str) {
    if(head == nullptr) {
        return false;
    }
    Trie *cur = head;
    for(auto it : str) {
        cur = cur->map[it];
        if(cur == nullptr) 
        return false;
    }
    return cur->isLeaf;
}

void prefixes(vector<string> &prefix,Trie *head, string word) {
    if(head == nullptr) 
    return;
    if(head->freq == 1) {
        prefix.push_back(word);
        return;
    }
    for(auto it: head->map) {
        prefixes(prefix,it.second, word + it.first);
    }
}

vector<string> smallestPrefix(vector<string> &words) {
    Trie *head = nullptr;
    for(auto it: words) {
        insert(head, it);
    }
    vector<string> prefix;
    prefixes(prefix, head, "");
    return prefix;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<string> words = { "AND", "BONFIRE", "BOOL", "CASE", "CATCH", "CHAR" };
    vector<string> prefixes = smallestPrefix(words);
    for(auto it: prefixes) {
        cout << it << endl;
    }
    return 0;
}