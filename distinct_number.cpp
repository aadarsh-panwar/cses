#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> s;
    while(n) {
        int num;
        cin >> num;
        s.insert(num);
        --n;
    }
    cout << s.size();
    return 0;
}