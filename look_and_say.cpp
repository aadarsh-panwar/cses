#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string num = to_string(1l);
    cout << num <<endl;
    for(int i =1;i<=10;++i) {
    string next_num = "";
    for(int i =0;i<num.size();) {
        char dig = num[i];
        int count = 1;
        ++i;
        while(i < num.size() && num[i] == dig){
            ++i;
            ++count;
        }
        next_num += to_string(count) + to_string(dig - '0');
    }

    num = next_num;
    cout << num << endl;
    }
    return 0;
}