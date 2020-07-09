#include <bits/stdc++.h>
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

const int MOD = 998244353;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using row = vector<int>; // Values are int!!
using matrix = vector<row>;

matrix initMatrix (int nRow, int nCol) {
	matrix ret (nRow, row(nCol));

	return ret;
}

matrix operator* (matrix &a, matrix &b) {
	assert (len (a) && len (a[0]) == len (b)); // check if (Ma(a x n), Mb(n x b)) holds
	int nRow = len (b);
	int nCol = min (len(a), len(b[0]));
	matrix ret = initMatrix (nRow, nCol);
	for (int i = 0; i < nRow; i++)
		for (int j = 0; j < nCol; j++)
			for (int k = 0; k < nRow; k++)
	ret[i][j] = (ret[i][j] + a[i][k] * 1LL * b[k][j])%(MOD-1); // Using mod and long long!!
	
	return ret;
}

void operator*= (matrix &a, matrix &b) {
	a = a*b;
}

matrix mat_powmod (matrix &a, int p) {
	matrix ret = initMatrix (len(a), len(a[0]));
	for (int i = 0; i < min (len (a), len(a[0])); i++)
		ret[i][i] = 1;

	while (p) {
		if (p&1)
			ret = a * ret;
		p >>= 1;
		a = a*a;
	}

	return ret;
}

int powMod (int b, int p, int m) {
	int ret = 1;
	while (p) {
		if (p&1)
			ret = (ret * 1LL * b)%m;
		p >>= 1;
		b = (b * 1LL * b) % m;
	}

	return ret;
}

int invMod (int b, int m) {
	return powMod (b, m-2, m);
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powMod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

int discLog (int b, int a, int m) {
	map<int, int> mp;
	int n = sqrt(m);
	for (int p = 1; p <= (m/n + 1); p++) {
		int now = powMod (b, n*p, MOD);
		mp[now] = p;
	}

	for (int q = 0; q <= n; q++) {
		int now = (a*1ll*powMod (b, q, MOD))%MOD;
		if (mp.count (now))
			return mp[now]*n - q;
	}

	return -1;
}

int main () {
	int k;
	scanf ("%d", &k);
	matrix nxt = initMatrix (k, k);
	for (int i = 1; i < k; i++)
		nxt[i-1][i] = 1;
	for (int i = 0; i < k; i++)
		scanf ("%d", &nxt[k-1][k-i-1]);

	int n, m;
	scanf ("%d %d", &n, &m);
	nxt = mat_powmod (nxt, n-k);
	matrix seq = initMatrix (k, 1);
	seq[k-1][0] = 1;
	seq = nxt*seq;


	int q = seq[k-1][0];
	int g = generator (MOD); // primitive root
	int gq = powMod (g, q, MOD);

	int r = discLog (gq, m, MOD);
	if (r == -1)
		printf ("-1\n");
	else
		printf ("%d\n", powMod (g, r, MOD));
	
	return 0;
}
