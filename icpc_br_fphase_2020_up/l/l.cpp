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

int n, m;
int q;
char mat[60][60];
int msk[60][60];

string get_string(int x, int y, int sz, int opt) {
	string ret = "";
	if(opt == 0) {
		for(int j = y; j <= y+sz-1; j++)
			ret += mat[x][j];
	} else if(opt == 1) {
		for(int i = x; i <= x+sz-1; i++)
			ret += mat[i][y];
	} else if(opt == 2) {
		for(int i = x, j = y; i <= x+sz-1; i++, j++)
				ret += mat[i][j];
	} else if(opt == 3) {
		for(int i = x, j = y; i <= x+sz-1; i++, j--)
				ret += mat[i][j];
	}
	// cout << "opt = " << opt << ", " << x << ", " << y << " -> " << ret << '\n';
	sort(ALL(ret));
	return ret;
}

void mark_string(int x, int y, int sz, int opt, int bit) {
	if(opt == 0) {
		for(int j = y; j <= y+sz-1; j++)
			msk[x][j] |= bit;
	} else if(opt == 1) {
		for(int i = x; i <= x+sz-1; i++)
			msk[i][y] |= bit;
	} else if(opt == 2) {
		for(int i = x, j = y; i <= x+sz-1; i++, j++)
				msk[i][j] |= bit;
	} else if(opt == 3) {
		for(int i = x, j = y; i <= x+sz-1; i++, j--)
				msk[i][j] |= bit;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string l;
		cin >> l;
		for(int j = 1; j <= m; j++)
			mat[i][j] = l[j-1];
	}

	cin >> q;
	while(q--) {
		string s;
		cin >> s;
		sort(ALL(s));
		int sz = LEN(s);
		// Line
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m-sz+1; j++)
				if(get_string(i, j, sz, 0) == s)
					mark_string(i, j, sz, 0, 1<<q);
		// Column
		for(int i = 1; i <= n-sz+1; i++)
			for(int j = 1; j <= m; j++)
				if(get_string(i, j, sz, 1) == s)
					mark_string(i, j, sz, 1, 1<<q);
		// Diagonal (backward slash)
		for(int i = 1; i <= n-sz+1; i++)
			for(int j = 1; j <= m-sz+1; j++)
				if(get_string(i, j, sz, 2) == s)
					mark_string(i, j, sz, 2, 1<<q);
		// Diagonal /
		for(int i = 1; i <= n-sz+1; i++)
			for(int j = sz; j <= m; j++)
				if(get_string(i, j, sz, 3) == s)
					mark_string(i, j, sz, 3, 1<<q);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans += (__builtin_popcount(msk[i][j]) > 1);
	cout << ans << '\n';

	return 0;
}
