#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; 
	cin>> t;
	while(t) {
	    
	    string str;
	    cin >> str;
	    if(str.size() <= 2) {
	        cout << "-1" << "\n";
	    }
	    else {
	        vector<bool> v(str.size());
	        int n = str.size();
	        for(int i = 1;i<n;++i) {
	            if(!(str[0] == str[i] || str[n-1] == str[i]))
	            v[i] = true;
	        }
            for(auto it : v) {
                cout << it << " ";
            }
            cout <<endl;
	        int mx = 0;
	        for(int i = 0,j;i<n;++i) {
                j = i+1;
	            while(j < n && v[i] == true && v[i] == v[j]) {
	                mx = max(j- i +1, mx);
	                ++j;
	            }
	        }
	        cout << mx << "\n";
	    }
	    --t;
	}
	
	return 0;
}
