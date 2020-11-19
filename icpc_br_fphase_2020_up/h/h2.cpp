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

const int N = (1 << 25) + 1;
ll vals[55], dp2[N];
vector<ll> vals_sep[30];
int ptA[30], ptB[30];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, k;
	ll a, b;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> vals[i];
	sort(vals, vals + n);
	cin >> a >> b;
	ll ans = 0;
	if(k == 1) {
		for(int i = 0; i < n; i++)
			ans += vals[i] >= a and vals[i] <= b;
	} else {
		int md1 = n/2;
		int md2 = n-md1;
		swap(md1, md2);
		vals_sep[0].push_back(0);
		for(int i = 0; i < md1; i++) {
			ll v = vals[i];
			for(int j = i;j >= 0; j--) {
				vector<ll> &nxt = vals_sep[j+1];
				for(int val : vals_sep[j]) {
					nxt.push_back(val+v);
				}
			}
		}
		exit(0);

		for(int i = 0; i <= md1; i++) {
			ptA[i] = LEN(vals_sep[i]);
			ptB[i] = LEN(vals_sep[i]);
		}
        --a;
		for(int i = 0; i < (1<<md2); i++) {
			int bt = k - __builtin_popcount(i);
			int lg = __builtin_ctz(i);
            if(i) dp2[i] = dp2[i - (1 << lg)] + vals[md1+lg];
            if(bt > min(k, md1)) continue;
			if(bt >= 0 and LEN(vals_sep[bt]) && dp2[i] <= b) {
				while(ptA[bt] and vals_sep[bt][ptA[bt] - 1] > a-dp2[i])
					ptA[bt]--;
				while(ptB[bt] and vals_sep[bt][ptB[bt] - 1] > b-dp2[i])
					ptB[bt]--;

				ans += ptB[bt]-ptA[bt];
			}
		}
	}
	cout << ans << '\n';
	

	return 0;
}
