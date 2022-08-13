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

const int N = (1 << 25) + 500;
ll vals[55], dp[N], dp2[N];
int popc[N], ctz[N];
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
		for(int i = 0; i < (1<<md1); i++) {
			int bt = popc[i] = __builtin_popcount(i);
			int lg = ctz[i] = __builtin_ctz(i);
            if(bt > k) continue;
			if(i) dp[i] = dp[i - (1 << lg)] + vals[lg];
            if(dp[i] > b) continue;
			vals_sep[bt].push_back(dp[i]);
		}

		for(int i = 0; i <= md1; i++) {
			ptA[i] = LEN(vals_sep[i]);
			ptB[i] = LEN(vals_sep[i]);
		}
        --a;
		for(int i = 0; i < (1<<md2); i++) {
			int bt = k - popc[i];
            if(bt > k) continue;
			int lg = ctz[i];
            if(i) dp2[i] = dp2[i - (1 << lg)] + vals[md1+lg];
			// cout << md + lg << ": " << vals[md + lg] << endl;
			// cout << bitset<3>(i) << ": " << dp2[i] << endl;
			if(bt >= 0 and LEN(vals_sep[bt]) && dp2[i] <= b) {
				// cout << "bt = " << bt << " dp2 = " << dp2[i] << '\n';
                // cout << "vals_now:";
                // for(ll j : vals_sep[bt]) cout <<" " << j;
                // cout << endl;
				// cout << "ptB: " << ptB[bt] << " ptA" << ptA[bt] << endl;
            
				while(ptA[bt] and vals_sep[bt][ptA[bt] - 1] > a-dp2[i])
					ptA[bt]--;
				while(ptB[bt] and vals_sep[bt][ptB[bt] - 1] > b-dp2[i])
					ptB[bt]--;
				// cout << "  pt = "  << ptA[bt] << " " << ptB[bt] << '\n';
				// cout << "  LEN =  "<< LEN(vals_now) << '\n';
				// auto st = lower_bound(ALL(vals_now), a-dp2[i]) - vals_now.begin();
				// auto en = upper_bound(ALL(vals_now), b-dp2[i]) - vals_now.begin();
				// cout << ptB[bt] << " - " << ptA[bt] <<  " = " << en << " - " << st << '\n';
				ans += ptB[bt]-ptA[bt];
				// ans += en - st;
			}
		}
	}
	cout << ans << '\n';
	

	return 0;
}
