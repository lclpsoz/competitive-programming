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

int n, k;
string s;
vector<int> qnt;
int maxi = 0;

int two_pointers(int st) {
	int l = st, r = st+1;
	int fr = k;
	int now = qnt[l];
	int ans = min(n, maxi + fr);
	while(r < LEN(qnt)) {
		if(qnt[r] <= fr) {
			fr -= qnt[r];
			now += qnt[r];
			++r;
			if(r < LEN(qnt))
				now += qnt[r++];
		} else if (l < r-1) {
			now -= qnt[l++];
			if(l < LEN(qnt)) {
				fr += qnt[l];
				now -= qnt[l++];
			}
		} else if(l+2 < LEN(qnt)) {
			l += 2;
			fr = k;
			r = l+1;
			now = qnt[l];
		} else
			break;
		ans = max(ans, min(now+fr, n));
	}

	return ans;
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	cin >> n >> k >> s;
	char c = '1';
	int q = 0;
	for(int i = 0; i < LEN(s); i++) {
		if(c != s[i]) {
			if(q) qnt.push_back(q);
			q = 1;
			c = s[i];
		} else
			q++;
		maxi = max(maxi, q);
	}
	if(q) qnt.push_back(q);

	int ans = two_pointers(0);
	if(LEN(qnt) > 1)
		ans = max(ans, two_pointers(1));

	cout << ans << '\n';

	return 0;
}
