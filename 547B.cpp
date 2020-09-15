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

const int N = 2e5 + 10;

int n;
set<pii> st;
vector<pii> vals;
int ans[N];
int lengths[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vals.push_back({x, i});
		ans[1] = max(x, ans[1]);
	}
	sort(vals.begin(), vals.end());
	reverse(ALL(vals));

	lengths[n] = 1;
	st.insert({n, 1});
	int maxi_len = n;
	do {
		while(lengths[maxi_len] == 0) {
			maxi_len--;
			ans[maxi_len] = ans[maxi_len+1];
		}
		int now = vals.back().x;
		ans[maxi_len] = now;
		while(LEN(vals) and vals.back().x == now) {
			int pos = vals.back().y;
			vals.pop_back();
			auto it = st.lower_bound({pos, -1});
			pii inter = *it;
			st.erase(it);
			lengths[inter.x-inter.y+1]--;
			if(pos > inter.y) {
				pii p = {pos-1, inter.y};
				lengths[p.x - p.y + 1]++;
				st.insert(p);
			}
			if(pos < inter.x) {
				pii p = {inter.x, pos+1};
				lengths[p.x - p.y + 1]++;
				st.insert(p);
			}
		}
	} while(LEN(vals));
	for(int i = 1; i < maxi_len; i++) ans[i] = ans[maxi_len];
	for(int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i==n]);

	return 0;
}
