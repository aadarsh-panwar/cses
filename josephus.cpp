#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int i;
    for( i =2;i<=n;i+=2) {
        cout << i << " ";
    }
    if(n%2 ==0) {
        i =3;
    }
    else {
        i = 1;
    }
    for(;i<=n;i+= 2) {
        cout << i << " ";
    }
    if(n > 1 && n%2==0)
    cout << 1 << " ";
    return 0;
}