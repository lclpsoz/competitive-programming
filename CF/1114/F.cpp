#include "stdio.h"
#include "algorithm"
#include "vector"
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

const int MOD = 1e9+7;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 4e5+10;

int n, q;
bool not_prime[310];
vector<int> primes;
int invMod[65];
ll allMsks[310];
pair<int, ll> arr[N];

void sieve () {
	for (int i = 2; i*i <= 300; i++)
		if (!not_prime[i])
			for (int j = i*i; j <= 300; j+=i)
				not_prime[j] = true;
			
	for (int i = 2; i <= 300; i++)
		if (!not_prime[i])
			primes.push_back (i);
}

int powMod (int b, ll p) {
	if (p < 0) return 0;
	int ret = 1;
	while (p) {
		if (p&1) ret = (ret * 1LL * b)%MOD;
		p >>= 1;
		b = (b * 1LL * b)%MOD;
	}
	
	return ret;
}

int _invMod (int b) {
	return powMod (b, MOD-2);
}

inline ll getMsk (int v) {
	ll &msk = allMsks[v];
	if (msk == -1) {
		msk = 0;
		for (int i = 0; i < len (primes); i++)
			if (v%primes[i] == 0)
				msk |= (1LL<<i);
	}
	return msk;
}

struct _multSegTree {
	int tree[4*N], lazy[4*N];
	
	void _build (int p = 1, int tl = 1, int tr = n) {
		if (tl == tr) {
			tree[p] = arr[tl].x;
			return;
		}
		int md = (tl+tr)/2;
		_build (2*p, tl, md);
		_build (2*p + 1, md+1, tr);
		tree[p] = (tree[2*p] * 1LL * tree[2*p+1])%MOD;
	}
	
	void build () {
		for (int i = 0; i < 4*N; i++)
			tree[i] = lazy[i] = 1;
		_build ();
	}
	
	void prop (int p, int l, int r) {
		if (lazy[p] == 1) return;
		if (l < r) {
			lazy[2*p] = (lazy[2*p] * 1LL * lazy[p])%MOD;
			lazy[2*p+1] = (lazy[2*p+1] * 1LL * lazy[p])%MOD;
		}
		tree[p] = (powMod(lazy[p], (r-l+1)) * 1LL * tree[p])%MOD;
		lazy[p] = 1;
	}
	
	void upd (int l, int r, int v, int p = 1, int tl = 1, int tr = n) {
		prop (p, tl, tr);
		if (l <= tl and tr <= r) {
			lazy[p] = v;
			prop (p, tl, tr);
			return;
		} else if (tr < l or r < tl)
			return;
		
		int md = (tl+tr)/2;
		upd (l, r, v, 2*p, tl, md);
		upd (l, r, v, 2*p + 1, md+1, tr);
		tree[p] = (tree[2*p] * 1LL * tree[2*p+1])%MOD;
	}
	
	int qry (int l, int r, int p = 1, int tl = 1, int tr = n) {
		prop (p, tl, tr);
		if (l <= tl and tr <= r)
			return tree[p];
		else if (tr < l or r < tl)
			return 1;
		
		int md = (tl+tr)/2;
		int ret = (	qry (l, r, 2*p, tl, md) * 1LL *
						qry (l, r, 2*p + 1, md+1, tr))%MOD;
		tree[p] = (tree[2*p] * 1LL * tree[2*p + 1])%MOD;
		
		return ret;
	}
};

struct _bitSegTree {
	ll tree[4*N], lazy[4*N];
	
	void _build (int p = 1, int tl = 1, int tr = n) {
		if (tl == tr) {
			tree[p] = arr[tl].y;
			return;
		}
		
		int md = (tl+tr)/2;
		_build (2*p, tl, md);
		_build (2*p+1, md+1, tr);
		tree[p] = tree[2*p] | tree[2*p+1];
	}
	
	void build () {
		for (int i = 0; i < 4*N; i++)
			tree[i] = lazy[i] = 0;
		_build ();
	}
	
	void prop (int p, int l, int r) {
		if (lazy[p] == 0) return;
		if (l < r) {
			lazy[2*p] |= lazy[p];
			lazy[2*p+1] |= lazy[p];
		}
		tree[p] |= lazy[p];
		lazy[p] = 0;
	}
	
	void upd (int l, int r, ll msk, int p = 1, int tl = 1, int tr = n) {
		prop (p, tl, tr);
		if (l <= tl and tr <= r) {
			lazy[p] |= msk;
			prop (p, tl, tr);
			return;
		} else if (r < tl or tr < l)
			return;
		
		int md = (tl+tr)/2;
		upd (l, r, msk, 2*p, tl, md);
		upd (l, r, msk, 2*p + 1, md+1, tr);
		tree[p] = tree[2*p] | tree[2*p+1];
	}
	
	void upd (int l, int r, int v) {
		upd (l, r, getMsk (v));
	}
	
	ll qry (int l, int r, int p = 1, int tl = 1, int tr = n) {
		prop (p, tl, tr);
		if (l <= tl and tr <= r)
			return tree[p];
		else if (r < tl or tr < l)
			return 0;
		
		int md = (tl+tr)/2;
		ll ret = 	qry (l, r, 2*p, tl, md) | 
					qry (l, r, 2*p + 1, md+1, tr);
		
		tree[p] = tree[2*p] | tree[2*p + 1];
					
		return ret;
	}
	
};

_multSegTree multSeg;
_bitSegTree bitSeg;

ll qry (int l, int r) {
	ll ret = multSeg.qry (l, r);
	ll msk = bitSeg.qry (l, r);
	for (int i = 0; i < len (primes); i++)
		if ((msk & (1LL<<i))) {
			ret =  (ret * (primes[i]-1))%MOD;
			ret =  (ret * invMod[i])%MOD;
		}
		
	return ret;
}

int main () {
	sieve();	
	for (int i = 1; i <= 300; i++)
		allMsks[i] = -1;
	for (int i = 0; i < len(primes); i++)
		invMod[i] = _invMod (primes[i]);
	
	scanf ("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		arr[i].x = x;
		arr[i].y = getMsk (x);
	}
	
	multSeg.build();
	bitSeg.build();
	
	char opt[15];
	int l, r, v;
	while (q--) {
		scanf ("%s %d %d", opt, &l, &r);
		if (l > r) swap (l, r);
		if (opt[0] == 'M') {
			scanf ("%d", &v);
			multSeg.upd (l, r, v);
			bitSeg.upd (l, r, v);
		} else
			printf ("%lld\n", (qry (l, r) + MOD)%MOD);
	}
	

	return 0;
}