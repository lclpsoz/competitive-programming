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

const int N = 510;
bitset<N> basis[N], id[N];
int n;

void insert(bitset<N> mask, bitset<N> k) {
	for (int i = 0; i < n; i++) if (mask[i]) {
		if (basis[i] == 0) {
			basis[i] = mask;
			id[i] = k;
			return;
		}
		mask ^= basis[i];
		k ^= id[i];
	}
}

bitset<N> bad;
bitset<N> get(bitset<N> mask) {
	bitset<N> ret = 0;
	for (int i = 0; i < n; i++) if (mask[i]) {
		if (basis[i] == 0) return bad;
		mask ^= basis[i], ret ^= id[i];
	}
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(1);

	cin >> n;

	vector<bitset<N>> a(n, 0);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			int b; cin >> b;
			if(b) a[i][j] = 1;
		}

	bad[N - 1] = 1;

	for(int i = 0; i < n; i++)
	{
		bitset<N> b(0);
		b[i] = 1;
		insert(a[i], b);
	}

	for(int i = 0; i < n; i++)
	{
		bitset<N> b(0);
		b[i] = 1;
		b = get(b);
		if(b == bad)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	for(int i = 0; i < n; i++)
	{
		bitset<N> b(0);
		b[i] = 1;
		b = get(b);

		bitset<N> now(0);
		for(int j = 0; j < n; j++)
			if(b[j]) cout << j + 1 << " ";
		cout << '\n';
	}

	return 0;
}
