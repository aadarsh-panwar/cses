#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>

using namespace std;
struct Node {
    int a,d,idx;
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Node> v(n);
    for(int i = 0;i<n;++i) {
        cin >> v[i].a >> v[i].d;
        v[i].idx = i;
    }
    auto cmp = [](const Node &a, const Node&b) ->bool {
        if(a.a == b.a) 
        return a.d < b.d;
        return a.a < b.a;
    };
    sort(v.begin(), v.end(),cmp);

    vector<int> order(n);
    int room = 0;
    typedef pair<int, int> pi;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int mx = 0;
    for(int i =0;i<n;++i) {
        if(pq.empty()) {
            ++room;
            pq.push({v[i].d, room});
            order[v[i].idx] = room;
        }
        else {
            if(pq.top().first < v[i].a) {
                pi p = pq.top();
                pq.pop();
                pq.push({v[i].d, p.second});
                order[v[i].idx] = p.second;
            }
            else {
                ++room;
                pq.push({v[i].d, room});
                order[v[i].idx] = room;
            }
        }
        mx = max<int>(mx, pq.size());
    }
    cout << mx << endl;
    for(auto it: order) {
        cout << it << " ";
    }
    return 0;
}