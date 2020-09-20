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

const int N = 1e5 + 100;

ll n;
int x, m;
set<int> st;
ll acu[N];
int pos_st[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> x >> m;
	ll ans = 0;
	int qnt = 0;
	for(int i = 1; pos_st[x] == 0; i++) {
		pos_st[x] = i;
		ans = ans + x;
		acu[i] = ans;
		qnt++;
		st.insert(x%m);
		x = (x*1ll*x)%m;
	}

	int start_cycle = pos_st[x];
	int end_cycle = qnt;
	// cout << "cycle = " << start_cycle << ' ' << end_cycle << '\n';
	qnt = end_cycle-start_cycle+1;
	ll cycled = ans-acu[start_cycle-1];
	// cout << "cycled = " << cycled << " | " << cycled*1LL*((n-start_cycle+1)/qnt) << '\n';
	// cout << "pre-cycle: " << acu[(int)min(n, (ll)start_cycle-1)] << '\n';
	ll beforeCycle = acu[(int)min(n, (ll)start_cycle-1)];
	ll inCycle = cycled*1LL*((n-start_cycle+1)/qnt);
	int lSt = (start_cycle-1);
	ll afterCycle = 0;
	if(n >= start_cycle)
		afterCycle = (acu[lSt + (n-start_cycle+1)%qnt]-acu[lSt]);
	// cout << "in: " << inCycle << '\n';
	// cout << "after: " << afterCycle << '\n';
	ans = beforeCycle + inCycle + afterCycle;
			
	cout << ans << '\n';



	return 0;
}
