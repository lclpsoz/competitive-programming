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
		int n;
		cin >> n;
		vi vec;
		while(n--) {
			int x;
			cin >> x;
			if(LEN(vec) == 0 or vec.back() != x)
				vec.push_back(x);
		}
		vi comp = vec;
		sort(ALL(comp));
		comp.resize(unique(ALL(comp)) - comp.begin());
		for(int i = 0; i < LEN(vec); i++)
			vec[i] = lower_bound(ALL(comp), vec[i]) - comp.begin();
		vector<vi> vecs(LEN(vec)+1);
		for(int i = 0; i < LEN(vec); i++)
			vecs[vec[i]].push_back(i);
		int ans = 1e9;
		for(int i = 0; i < LEN(vec); i++) {
			vi &now = vecs[i];
			if(LEN(now)) {
				int v_now = 0;
				if(now.front() > 0)
					v_now++;
				if(now.back() < LEN(vec)-1)
					v_now++;
				v_now += LEN(now)-1;
				ans = min(v_now, ans);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
