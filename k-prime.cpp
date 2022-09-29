#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
const int MAX = 100000+1;
using namespace std;
typedef vector<int> vi;
void seive(vi &prime ) {
    int n =prime.size();
    for(int i = 2;i*i<n;++i){
        if(prime[i] != 0)
        continue;
        prime[i] = i;
        for(int j = i*i;j<n;j+= i) {
            if(prime[j] ==0)
            prime[j] = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> prime(MAX, 0);
    seive(prime); 
    int t;
	cin >> t;
	while(t) {
	    int a, b, k;
	    cin >> a >> b >> k;
	    int cnt = 0;
	    for(int i = a;i<=b;++i) {
	        set<int> s;
	        int num = i;
	        while(num != 1) {
	            s.insert(prime[num]);
	            num = num/prime[num];
	        }
	        if(s.size() == k) 
	        ++cnt;
	    }
	    cout << cnt << endl;
	    --t;
	}
    return 0;
}