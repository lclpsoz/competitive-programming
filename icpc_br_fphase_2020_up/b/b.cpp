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

const int SHIFT = 50;

int mat[100][100];

void no() {
	cout << "N\n";
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	int d, l, r, c;
	cin >> n;

	while(n--) {
		cin >> d >> l >> r >> c;
		r += SHIFT;
		c += SHIFT;
		if(d == 0) {
			for(int i = 0; i < l; i++)
				mat[r][c+i]++;
		} else {
			for(int i = 0; i < l; i++)
				mat[r+i][c]++;
		}
	}

	for(int i = 1+SHIFT; i <= 10+SHIFT; i++)
		for(int j = 1+SHIFT; j <= 10+SHIFT; j++) {
			if(mat[i][j] > 1)
				no();
			mat[i][j] = 0;
		}
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			if(mat[i][j])
				no();
	cout << "Y\n";


	return 0;
}
