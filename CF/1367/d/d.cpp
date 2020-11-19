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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int t;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		string s;
		int m;
		cin >> s >> m;
		vi vec(m);
		for(int &v : vec)
			cin >> v;
		string ans = "";
		for(int i = 0; i < m; i++)
			ans.push_back('-');
		vi avail(310, 0), need(310, 0);
		for(char c : s)
			avail[c]++;
		string ref = ans;
		char cur = 'z';
		int fr = m;
		while(fr) {
			vi nxt;
			for(int i = 0; i < m; i++) {
				if(ref[i] == '-') {
					if(vec[i] == 0) {
						nxt.push_back(i);
						ref[i] = cur;
						need[cur]++;
						// s.pop_back();
						fr--;
					}
				}
			}
			cur--;
			for(int v : nxt)
				for(int i = 0; i < m; i++)
					if(vec[i])
						vec[i] -= abs(i-v);
					else
						vec[i] = -1;
		}
		char p = 'z';
		char p2 = 'z';
		while(p2 >= 'a') {
			if(need[p2]) {
				while(avail[p] < need[p2]) p--;
				for(int i = 0; i < m; i++)
					if(ref[i] == p2)
						ans[i] = p;
				--p;
			}
			p2--;
		}

		cout << ans << '\n';
	}

	return 0;
}
