#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, k, ans=0;
   cin >> n >> m >> k;
   vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
	while (i < n && j < m){
		// Found a suitable apartment for the applicant
		if (abs(a[i] - b[j]) <= k){
			++i; ++j;
			++ans;
		}
		else{
			// If the desired apartment size of the applicant is too big,
			// move the apartment pointer to the right to find a bigger one
			if (a[i] - b[j] > k){
				++j;
			}
			// If the desired apartment size is too small,
			// skip that applicant and move to the next person
			else{
				++i;
			}
		}
	}
	cout << ans << "\n";

    return 0;
}