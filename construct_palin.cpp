#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

bool canMakePalindrome(string &str) {
    int len = str.size();
    if(len == 0) {
        return false;
    }
    unordered_map<char, int> freq;
    for(auto it : str) {
            ++freq[it];
    }
    int even = 0;
    int odd = 0;
     for(auto it : freq) {
            if(it.second%2 ==0)
            ++even;
            else 
            ++odd;
        if(odd > 1)
        return false;
        }
    return true;

    // aa b cc -> a->2, b->2

    // if(len%2 ==0) {
    //     //aa bb cd 
    //     // a -> 2, b -> 2, c -> 1, d -> 1
    //     for(auto it : freq) {
    //         if(it.second%2 != 0)
    //         return false;
    //     }
    //     return true;
    // }
    // else {
    //     // aa cc d aa 
    //     // a-> 4, c-> 2, d->1
    //     int oneFreqChar = 0;
    //     for(auto it: freq) {
    //         if(it.second%2 != 0) {
    //             oneFreqChar++;
    //             if(oneFreqChar > 1)
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    return false;
}

int main() {
    string str;
    cin >> str;
    cout << "input string" << str << endl;
    cout << "Can make palindrome:"<< canMakePalindrome(str) <<endl;
    
    return 0;
}