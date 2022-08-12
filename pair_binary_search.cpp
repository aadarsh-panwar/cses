#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;
typedef pair<int,int> pi;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
	cin >> t;
	while(t) {
	   int n,m;
	   cin >> n >>m;
	   vector<pi> v(n);
	   for(int i =0;i<n;++i) {
	       cin >> v[i].first >> v[i].second;
	   }
	   sort(v.begin(), v.end());
	   for(int i =0;i<m;++i) {
	       int c;
	       cin >> c;
           auto cmp = [](const pi &a, const pi &b)->bool {
               if(a.first <= b.first && a.second > b.first)
               return true;
               return false;
           };
	       auto idx = upper_bound(v.begin(), v.end(),make_pair(c,c), cmp);
           if(idx != v.end())
           cout << idx - v.begin() <<endl;
           else 
           cout << -1 <<endl;
	       
	   }
	    --t;
	}
	
    return 0;
}