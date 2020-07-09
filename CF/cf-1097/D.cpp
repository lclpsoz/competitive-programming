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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
	return (int)(x%m);
}

////////////////////////// Solution starts below. //////////////////////////////

// --------------------------------------------------------------------- //
// POLLARD RHO FROM http://morris821028.github.io/2015/07/11/uva-11476/  //
// --------------------------------------------------------------------- //

#define MAXL (50000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))
int mark[MAXL];
int P[50000], Pt = 0;
void sieve() {
    register int i, j, k;
    SET(1);
    int n = 46340;
    for (i = 2; i <= n; i++) {
        if (!GET(i)) {
            for (k = n/i, j = i*k; k >= i; k--, j -= i)
                SET(j);
            P[Pt++] = i;
        }
    }
}
long long mul(unsigned long long a, unsigned long long b, unsigned long long mm) { 
    long long ret = 0; 
    for (a %= mm, b %= mm; b != 0; b >>= 1, a <<= 1, a = a >= mm ? a - mm : a) {
        if (b&1) {
            ret += a;
            if (ret >= mm)	ret -= mm;
        }
    } 
    return ret; 
}
void exgcd(long long x, long long y, long long &g, long long &a, long long &b) {
    if (y == 0)
        g = x, a = 1, b = 0;
    else
        exgcd(y, x%y, g, b, a), b -= (x/y) * a;
}
long long llgcd(long long x, long long y) {
    if (x < 0)    x = -x;
    if (y < 0)    y = -y;
    if (!x || !y)    return x + y;
    long long t;
    while (x%y)
        t = x, x = y, y = t%y;
    return y;
}
long long inverse(long long x, long long p) {
    long long g, b, r;
    exgcd(x, p, g, r, b);
    if (g < 0)	r = -r;
    return (r%p + p)%p;
}
long long mpow(long long x, long long y, long long mm) { // mm < 2^32 
    long long ret = 1;
    while (y) {
        if (y&1) 
            ret = (ret * x)%mm;
        y >>= 1, x = (x * x)%mm;
    }
    return ret % mm;
}
long long mpow2(long long x, long long y, long long mm) {
    long long ret = 1;
    while (y) {
        if (y&1) 
            ret = mul(ret, x, mm);
        y >>= 1, x = mul(x, x, mm);
    }
    return ret % mm;
}
int isPrime(long long p) { // implements by miller-babin
    if (p < 2 || !(p&1))	return 0;
    if (p == 2)				return 1;
    long long q = p-1, a, t;
    int k = 0, b = 0;
    while (!(q&1))	q >>= 1, k++;
    for (int it = 0; it < 2; it++) {
        a = rand()%(p-4) + 2;
        t = mpow2(a, q, p);
        b = (t == 1) || (t == p-1);
        for (int i = 1; i < k && !b; i++) {
            t = mul(t, t, p);
            if (t == p-1)
                b = 1;
        }
        if (b == 0)
            return 0;
    }
    return 1;
}
long long pollard_rho(long long n, long long c) {
    long long x = 2, y = 2, i = 1, k = 2, d;
    while (true) {
        x = (mul(x, x, n) + c);
        if (x >= n)	x -= n;
        d = llgcd(x - y, n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}
void factorize(int n, vector<long long> &f) {
    for (int i = 0; i < Pt && P[i]*P[i] <= n; i++) {
    	if (n%P[i] == 0) {
    		while (n%P[i] == 0)
    			f.push_back(P[i]), n /= P[i];
    	}
    }
    if (n != 1)	f.push_back(n);
}
void llfactorize(long long n, vector<long long> &f) {
    if (n == 1)	
        return ;	
    if (n < 1e+9) {
        factorize(n, f);
        return ;
    }
    if (isPrime(n)) {
        f.push_back(n);
        return ;
    }
    long long d = n;
    for (int i = 2; d == n; i++)
        d = pollard_rho(n, i);
    llfactorize(d, f);
    llfactorize(n/d, f);
}

// --------------------------------------------------------------------- //
// --------------------------------------------------------------------- //


int powMod (int b, int p) {
	int r = 1;
	while (p) {
		if (p&1) r = mod (r * 1LL * b);
		b = mod (b * 1LL * b);
		p >>= 1;
	}
	
	return r;
}

int invMod (int b) {
	return powMod (b, MOD-2);
}

void funcDivs (int p, vector<ll> &uniq, map<ll, int> &qntFact, vector<ll> &divs, ll val) {
	if (p == len (uniq)) {
		divs.push_back (val);
		return;
	}
	ll ax = 1;
	int &mx = qntFact[uniq[p]];
// 	printf ("%d %lld %d val(%lld)\n", p, uniq[p], mx, val);
	for (int i = 0; i <= mx; i++) {
		funcDivs (p+1, uniq, qntFact, divs, val*ax);
		ax *= uniq[p];
	}
}

pair<ll, ll> operator+ (pair<ll, ll> &p1, pair<ll, ll> &p2) {
	pair<ll, ll> r;
	r.x = mod (p1.x * 1LL * p2.y);
	r.x = mod (r.x + mod (p2.x * 1LL * p1.y));
	r.y = mod (p1.y * 1LL * p2.y);
	return r;
}

int main() {
	ll n; int k;
	vector<ll> factors, uniqFactors, divs;
	map<ll, int> mpFactors;
	
	scanf ("%lld %d", &n, &k);
	
    sieve();
		
	llfactorize(n, factors);
	for (auto &x : factors) {
		if (mpFactors.count (x) == 0)
			uniqFactors.push_back (x);
		mpFactors[x]++;
	}

	// Get divs of n
	funcDivs (0, uniqFactors, mpFactors, divs, 1ll);
	sort (divs.begin(), divs.end());
//  	for (ll u : divs)
//  		printf ("%lld ", u);
//  	putchar ('\n');
	int numDivs = len (divs);
	
	// -----
	
	vector<pair<ll, ll>> odds(numDivs, {1, len (divs)});
	vector<vector<int>> divsOf (numDivs);
// 	printf ("%d\n", len (odds));
	
	for (int i = 0; i < numDivs; i++)
		for (int j = 0; j <= i; j++)
			if (divs[i]%divs[j] == 0)
				divsOf[i].push_back (j);
	
	// -----
			
	for (int i = 0; i < k-1; i++) {
// 		printf ("LOLz\n");
		vector<pair<ll, ll>> oddsAux(numDivs, {0, 1});
		for (int i = 0; i < numDivs; i++) {
			vector<int> &divsNow = divsOf[i];
			ll nDivsNow = len (divsNow);
			pair<ll, ll> oddNow = odds[i];
			oddNow.y = mod (oddNow.y * 1LL * nDivsNow);
			for (int v : divsNow)
				oddsAux[v] = oddsAux[v] + oddNow;
		}

		odds = oddsAux;
	}
// 	for (auto p : odds)
// 		printf ("%lld / %lld\n", p.x, p.y);
	
	// -----
	
	for (int i = 0; i < len (divs); i++)
		odds[i].x = mod (odds[i].x * 1LL * divs[i]);
	pair<ll, ll> ans = {0, 1};
	for (int i = 0; i < len (divs); i++)
		ans = ans + odds[i];
	printf ("%lld %lld\n", ans.x, ans.y);
// 	printf ("%lld/%lld\n", ans.x, ans.y);
	printf ("%d\n", mod (ans.x * 1LL * invMod (ans.y)));
	
	// BRUTE TO K = 1
// 	ll sum = 0;
// 	for (auto v : divs)
// 		sum += v;
// 	printf ("sum: %lld\n", sum);
// 	int inv = invMod (numDivs);
// 	printf ("%d\n", mod (inv * 1LL * mod(sum)));
	
    return 0;
}