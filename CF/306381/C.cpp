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

const int N = 1e5 + 10, K = 30;
int a[N], n, nxt1[N], nxt2[N], s, cnt[K], ptr[K], ptrz;
vi z, x[K];
bool vis[N];

void sort(int i) {
	if(i == n) return;

	cout << a[i] << ' ';

	vis[i] = true;

	if(a[i])
	{
		for(int j = 0; j < K; j++)
			if((nxt1[i] & s) & (1 << j))
				if(--cnt[j] == 0) s ^= 1 << j;

		while(nxt1[i] & s)
		{
			int nxt = n;
			for(int j = 0; j < K; j++)
				if((nxt1[i] & s) & (1 << j))
				{
					while(vis[x[j][ptr[j]]]) ptr[j]++;
					nxt = min(nxt, x[j][ptr[j]]);
				}
			sort(nxt);
		}
	}

	while((nxt2[i] & s) || ptrz < LEN(z))
	{
		int nxt = n;
		while(ptrz < LEN(z) && vis[z[ptrz]]) ptrz++;
		if(ptrz < LEN(z)) nxt = min(nxt, z[ptrz]);
		for(int j = 0; j < K; j++)
			if((nxt2[i] & s) & (1 << j))
			{
				while(vis[x[j][ptr[j]]]) ptr[j]++;
				nxt = min(nxt, x[j][ptr[j]]);

			}
		sort(nxt);
	}
}

int main () {
	// freopen("sorting.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		for(int j = 0; j < K; j++)
			if(a[i] & (1 << j)) x[j].emplace_back(i), nxt1[i] |= 1 << j, cnt[j]++;
			else nxt2[i] |= 1 << j;

		if(!a[i]) z.emplace_back(i);
	}

	for(int j = 0; j < K; j++)
		if(!empty(x[j])) s |= 1 << j;

	sort(0);

	return 0;
}
