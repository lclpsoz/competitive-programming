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

const int N = 1010;

int n, m;
bool verif[N];
int vals[N];
vector<int> adj[N];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &vals[i]);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		adj[x].push_back (y);
		adj[y].push_back (x);
	}
	
	int qnt = n;
	ll ans = 0;
	while (qnt) {
		int now = -1'000'000'000 ;
		int choosen;
		int degree = -1;
		int mx;
		for (int i = 1; i <= n; i++) {
			if (!verif[i]) {
				if (vals[i] > now) { // Largers values first
					now = vals[i];
					choosen = i;
					degree = 0;
					mx = 0;
					for (int v : adj[i])
						if (!verif[v]) {
							mx += vals[v]; 
							++degree;
						}
				} else if (vals[i] == now) {
					int ax = 0;
					int mxAux = 0;
					for (int v : adj[i]) {
						if (!verif[v]) {
							ax++;
							mxAux += vals[v];
						}
					}
					if (ax > degree) {  // Larger degree first
						degree = ax;
						choosen = i;
						mx = mxAux;
					}
				}
			}
		}
		verif[choosen] = true;
		vals[choosen] = 0;
		//printf ("|%d\n", mx);
		ans += mx;
		--qnt;
	}
	
	printf ("%lld\n", ans);

	return 0;
}
