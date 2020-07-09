#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int M = 42, N = (1<<20) + 10;

int n, m, md;
map<string, int> mp;
ll adj[M];
ll can[M];
int qnt[N];
vector<pair<int, ll>> vec;

int getQnt (int msk) {
	int ret = 0;
	for (int i = 0; i < 30; i++)
		if (msk & (1<<i)) {
			msk^=(1<<i);
			ret = max (ret, qnt[msk]);
			msk^=(1<<i);
		}
	
	return ret;
}

int getValid (ll msk) {
	ll ret = (1ll<<(m-md))-1; // MASK FOR THE INVERSE
	for (int i = md; i < m; i++)
		if (msk & (1ll<<i))
			ret = ret&can[i];
			
	assert (ret < (1<<25));
	return (int)ret;
}

bool isValid (ll msk) {
	for (int i = 0; i < m; i++)
		if ((msk & (1LL << i)) and (msk & adj[i]))
			return false;
		
	return true;
}

int main () {
	cin.tie (0); ios::sync_with_stdio (false);
	
	int p = 0;
	cin >> n >> m;
	
	if (m == 1) {
		cout << 1 << '\n';
		exit (0);
	}
	
	ll now = 0;
	for (int i = 0; i < n; i++) {
		int opt;
		string str;
		cin >> opt;
		if (opt == 1) {
			if (now) {
				for (int j = 0; j < m; j++)
					if (now&(1LL<<j))
						adj[j] |= now;
				now = 0;
			}
		} else {
			cin >> str;
			if (!mp.count (str))
				mp[str] = p++;
			now |= (1LL<<mp[str]);
		}
	}
	if (now) {
		for (int j = 0; j < m; j++)
			if (now&(1LL<<j))
				adj[j] |= now;
		now = 0;
	}
	
	for (int i = 0; i < m; i++) {
		can[i] = ((~adj[i]) & ((1LL << m)-1));
		adj[i] ^= (1LL << i);
		can[i] ^= (1LL << i);
	}
	
	md = m/2; // {[0, md-1], [md, m-1]} | Right is larger, (m-md) elements vs md elements
	ll lst = 1ll<<(m-md);
	assert (lst < (1<<25));
	for (ll i = 1; i < lst; i++)
		vec.push_back ({__builtin_popcountll (i), i});
	sort (vec.begin(), vec.end());
	
	for (pair<int, ll> pp : vec) {
		if (pp.x == 1)
			qnt[pp.y] = 1;
		else {
			if (isValid (pp.y))
				qnt[pp.y] = pp.x;
			else
				qnt[pp.y] = getQnt ((int)pp.y);
		}
	}
	
	int ans = 0;
	lst = 1ll<<md;
	for (ll i = 0; i < lst; i++) {
		now = i<<(m-md);
		if (isValid (now)) {
			int msk = (int)getValid (now);
			
			ans = max (ans, __builtin_popcountll (i) + qnt[msk]);
		}
	}
	
	printf ("%d\n", ans);
	
	return 0;
}
