#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t) {
	    int n,x;
	    cin >> n >> x;
	    string str(n, 'a');
	    if(n%2 ==0 && x <= n/2) {
	        int i;
	         for( i =0;i<x;++i) {
	             str[i] = 'a' + i;
	         }
	         while(i < n) {
	             str[i] = str[i - x];
	             ++i;
	         }
	         
	         cout << str << "\n";
	    }
	    else if(n%2 != 0 && x <= n/2 +1) {
	        int i;
	         int m = n/2;
	         str[m] = 'a';
	         --x;
	         for(int i=1;i<n/2;++i) {
	             if(x >0) {
	                 str[m+i] = 'a' + i;
	                 str[m-i] = 'a' +i;
	                 --x;
	             }
	             else {
	                 str[i+m] = 'a';
	                 str[m-i] = 'a';
	             }
	         }
	         
	         cout << str << "\n";
	    }
	    else 
	    cout << -1 << endl;
	    --t;
	}
	
	return 0;
}
