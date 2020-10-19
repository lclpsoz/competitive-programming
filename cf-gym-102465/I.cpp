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

int mat[1010][1010];

int sum(pii x, pii y) {
	return mat[y.x][y.y]
			- mat[y.x][x.y-1]
			- mat[x.x-1][y.y]
			+ mat[x.x-1][x.y-1];
}

int get_qnt(int x, int y, char c) {
	int v = 3*x+2*y;
	int h = 2*x+y;
	if(c == 'a')
		return 2*(x*v) + 2*y*x;
	else if(c == 'b')
		return 2*x*v + 3*y*x;
	else
		return 1*x*v + 2*(y+x)*x;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for(int j = 1; j <= m; j++)
			mat[i][j] = s[j-1]=='#' + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
	}


	return 0;
}
