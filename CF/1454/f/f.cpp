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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		map<int, int> lft, rig, qnt;
		vi vals, arr = {-1};
		for(int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			rig[x] = i;
			if(lft.count(x) == 0)
				lft[x] = i;
			vals.push_back(x);
			arr.push_back(x);
			qnt[x]++;
		}
		if(qnt.rbegin()->y >= 3) {
			int v = qnt.rbegin()->x;
			cout << "YES\n";
			int md = -1;
			for(int i = lft[v]+1;;i++)
				if(arr[i] == v) {
					md = i;
					break;
				}
			cout << md-1 << ' ' << 1 << ' ' << n-md << '\n';
		}
		else {
			sort(ALL(vals));
			vals.resize(unique(ALL(vals))-vals.begin());
			reverse(ALL(vals));
			int mini = INF<int>;
			int l, r;
			bool ans = false;
			for(int v : vals) {
				// cout << "v = " << v << ", l = " << l << ", r = " << r << '\n';
				if(mini == INF<int>) {
					l = lft[v], r = rig[v];
					for(int i = l; i <= r; i++)
						mini = min(mini, arr[i]);
				}
				else if(mini >= v and lft[v] < l and r < rig[v]) {
					if(mini == v)
						ans = true;
					else {
						if(lft[v] < l-1 and arr[l-1] == v) {
							ans = true;
							l--;
						}
						else if(r+1 < rig[v] and arr[r+1] == v) {
							ans = true;
							r++;
						}
					}
				}

				if(!ans) {
					while(l > lft[v])
						mini = min(mini, arr[--l]);
					while(r < rig[v])
						mini = min(mini, arr[++r]);
				}
				else
					break;
			}
			if(ans)
				cout << "YES\n" << l-1 << ' ' << r-l+1 << ' ' << n-r << '\n';
			else
				cout << "NO\n";
		}
	}

	return 0;
}
