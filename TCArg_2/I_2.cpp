#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

const int N = 1e5 + 10, B = 400;
int n, m, a[N], b[N];
int block[N / B], val[N];
bool ok[N / B];

void build()
{
	for(int i = 0; i < n; i++)
		val[i] = -1, block[i / B] = -1, block[i / B] = true;
}

void update(int x, int y, int k)
{
	if(x / B != y / B)
	{
		if(ok[x / B])
		{
			if(block[x / B] != -1)
			{
				for(int i = 0; i < x % B; i++)
					val[x / B + i] = block[x / B] + i;
			}
			else
			{
				for(int i = 0; i < x % B; i++)
					val[x / B + i] = block[x / B];
			}
			ok[x / B] = false;
		}
		while(x % B) val[x++] = k++;
		while(x / B < y / B) block[x / B] = k, ok[x / B] = true, k += B, x += B;
	}
	while(x <= y) val[x++] = k++;
	if(ok[y / B])
	{
		if(block[y / B] != -1)
		{
			for(int i = B - 1; i > y % B; i--)
				val[y / B + i] = block[y / B] + i;
		}
		else
		{
			for(int i = B - 1; i > y % B; i--)
				val[y / B + i] = -1;
		}
		ok[y / B] = false;
	}
}

int query(int p)
{
	if(ok[p / B])
	{
		if(block[p / B] == -1) return b[p];
		return a[block[p / B] + p % B];
	}

	if(val[p] == -1) return b[p];
	return a[val[p]];
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	build();

	while(m--)
	{
		int t; cin >> t;
		if(t == 2)
		{
			int p; cin >> p;
			cout << query(--p) << endl;
		}
		else
		{
			int x, y, k;
			cin >> x >> y >> k;
			--x, --y;
			update(y, y + k - 1, x);
		}
	}

	return 0;
}
