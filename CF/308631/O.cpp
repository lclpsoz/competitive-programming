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

vector<int> z_function(vector<ll> s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m, l, k;
	cin >> n >> m;
	vector<vector<ll>> mat(n, vector<ll>(m-k+1));
	cin >> l >> k;
	for (int i = 0; i < n; i++) {
		vector<ll> &cur_lin = mat[i];
		string lin;
		cin >> lin;
		ll now = 0;
		for (int j = 0; j < k; j++)
			if (lin[j]=='*')
				now |= (1LL<<(k-j-1));
		cur_lin[0] = now;
		for (int j = 0; j < m-k; j++) {
			now = (now<<1)&((1LL<<k)-1);
			if (lin[j+k] == '*')
				now |= 1;
			cur_lin[j+1] = now;
		}
	}

	vector<ll> pat;
	for (int i = 0; i < l; i++) {
		string lin;
		cin >> lin;
		ll now = 0;
		for (int j = 0; j < k; j++)
			if (lin[j]=='*')
				now |= (1LL<<(k-j-1));
		pat.push_back(now);
	}

	// for (int i = 0; i < n; i++) {
	// 	// cerr << LEN(mat[i]) << '\n';
	// 	for (int j = 0; j <= m-k; j++)
	// 		cerr << mat[i][j] << " \n"[j==m-k];
	// }

	// for (int i = 0; i < l; i++)
	// 	cerr << pat[i] << '\n';

	int mx_n = n;
	int mx_m = m-k+1;
	ll FLAG = ((1LLU<<63)-10);
	vector<ll> z_s(n+l+1, FLAG+1);
	for (int i = 0; i < l; i++)
		z_s[i] = pat[i];
	z_s[l] = FLAG;

	for (int j = 0; j < mx_m; j++) {
		for (int i = 0; i < mx_n; i++)
			z_s[i+l+1] = mat[i][j];
		// cerr << "z_s = " << LEN(z_s) << '\n';
		// for (int i = 0; i < LEN(z_s); i++)
		// 	cerr << z_s[i] << ' ';
		// cerr << '\n';
		vi z = z_function(z_s);
		for (int i = l+1; i < l+1+n; i++)
			if (z[i] == l) {
				cout << i-(l+1) << ' ' << j << '\n';
				exit(0);
			}
	}
	cout << "-1 -1\n";

	return 0;
}
