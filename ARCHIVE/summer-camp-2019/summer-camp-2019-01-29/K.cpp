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

const int N = 1e5+10;

int n, m, q;
int his[N], size[N], link[N];
int tempo = 1;
bool not_prime[N];
vector<int> primes;

int find (int a, int t = N+10) {
//     printf ("FIND: %d %d\n", link[a], a);
    if (link[a] == a) return a;
    if (his[a] > t) return a; // EQUALS OR NOT??
    return find (link[a], t);
}

bool same (int a, int b, int t = N+10) {
    return find (a, t) == find (b, t);
}

void unite (int a, int b) {
    a = find (a);
    b = find (b);
    if (same (a, b)) return;
    if (size[a] > size[b])
        swap (a, b);
    size[b] += size[a];
    link[a] = b;
    his[a] = tempo;
    
//     for (int i = 1; i <= n; i++)
//         printf ("%d: %d %d %d\n", i, link[i], size[i], his[i]);
//     printf ("________________\n");
}

void sieve () {
    int i = 2;
    for (; i*i < N; i++)
        if (!not_prime[i]) {
            primes.push_back (i);
            for (int j = i*i; j < N; j+=i)
                not_prime[j] = true;
        }
    for (; i < N; i++)
        if (!not_prime[i])
            primes.push_back (i);
}

void buildUF () {
    reverse (primes.begin(), primes.end());
	bool ok = false;
	for (int p = m; p > 1; p--) {
// 		if (not_prime[p]) continue;
        for (int i = p; i <= n; i+=p)
            if (!same (p, i)) {
// 				printf ("%d %d\n", p, i);
                unite (p, i);
				ok = true;
            }
            
		tempo++;
    }
    for (int i = 1; i <= n; i++)
        if (!same (1, i)) {
            unite (1, i);
//             printf ("%d %d\n", 1, i);
        }
}

int solve (int a, int b) {
    int l = 0, r = tempo+1;
    while (l < r) {
        int md = (l+r)/2;
//         printf ("%d %d %d: %d (%d, %d)\n", l, md, r, same (l, r, md), find (a, md), find (b, md));
        if (!same (a, b, md))
            l = md+1;
        else
            r = md;
    }
    
    return l;
}

int main () {    
    scanf ("%d %d %d", &n, &m, &q);
    
    
    
    for (int i = 1; i <= n; i++)
        his[i] = 0, size[i] = 1, link[i] = i;
    sieve ();
    buildUF ();
//     for (int i = 1; i <= n; i++)
//         link[i] = find (i, N+10);
//     for (int i = 1; i <= n; i++)
//         printf ("%d: %d %d %d\n", i, link[i], size[i], his[i]);
//     printf ("________________\n");
//     printf ("test: %d %d\n", find (3, 1), find (6, 1));
    
    while (q--) {
        int x, y;
        scanf ("%d %d", &x, &y);
        printf ("%d\n", solve (x, y));
    }

	return 0;
}
