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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

bool has_zero(ll n) {
	while(n) {
		if(!(n % 10)) return true;
		n /= 10;
	}
	return false;
}

int brute(int n) {
	int count = 0;
	int cur = 0;
	while (count < n) {
		cur++;
		if (!has_zero(cur))
			count++;
	}
	return cur;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	ll n, k;
	//cin >> n >> k;

	k = 0;

	for (int I = 1; I < 1000; I++) {
		cout << "test: " << I << endl;
		n = I;
		int ans_a = brute(n);
		int ans_b = 0;
		int skipped;
		if(!k) {
			int tmp = n;
			vector<int> digs;
			while (n) {
				digs.push_back(n % 10);
				n /= 10;
			}
			n = tmp;
			skipped = 0;

			for (int i = 1; i < digs.size(); i++)
				skipped += digs[i] * pow(10, i - 1);

			n += skipped;
			vector<int> new_digs;
			while (n) {
				new_digs.push_back(n % 10);
				n /= 10;
			}
			skipped = 0;
			for (int i = 0; i < digs.size(); i++) {

			}
			
			vector<int> ans;
			while (n) {
				ans.push_back(n % 10);
				n /= 10;
			}
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				ans_b = ans[i] + ans_b * 10;
		}
		if (ans_a != ans_b) {
			cout  << "ops" << endl;
			cout << "skipped: " << skipped << endl;
			cout << ans_a << " " << ans_b << endl << endl;
			return 0;
		}
	}

	return 0;

	vector<ll> p = {1};
	for(int i = 1; i <= 10; i++)
		p.emplace_back(p.back() * 9);

	string s;
	bool gg = false;
	for(int i = 10; i >= 0; i--) {
		ll b = 0;
		while(n >= p[i]) b++, n -= p[i];

		if(!gg && !b) continue;
		gg = true;
		if(b >= k) b++;
		s.push_back(char(b + '0'));
	}

	cout << s << endl;

	return 0;
}
