#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n;
    cin >> n;
    map<string, int> mp;
    vector<int> execs;
    vector<int> adj[n + 1];
    int count = 1;
    for (int i = 0; i < n; i++) {
    	string name;
    	int k;
    	cin >> name >> k;
    	if (!mp[name])
    		mp[name] = count++;
    	int j;
    	for (j = 0; name[j] != ':'; j++);
    	j += 2;
    	if (name.compare(j, name.size() - j, "PROGRAM") == 0)
    		execs.push_back(mp[name]);

    	for (j = 0; j < k; j++) {
    		string call_name;
    		cin >> call_name;
    		if (!mp[call_name])
    			mp[call_name] = count++;
    		adj[mp[call_name]].push_back(mp[name]);
    	}
    }

    vector<bool> vis(n + 1, false);
    queue<int> q;
    for (int e : execs) {
    	q.push(e);
    	while (!q.empty()) {
    		int v = q.front();
    		vis[v] = true;
    		q.pop();
    		for (int u : adj[v]) {
    			if (!vis[u]) {
    				q.push(u);
    			}
    		}
    	}
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	if (!vis[i])
    		ans++;
    }
    cout << ans << endl;
	return 0;
}
