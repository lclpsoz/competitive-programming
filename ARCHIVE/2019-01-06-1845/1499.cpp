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

const int N = 4e4+100;

int n, q;
int qnt1[N], qnt2[N];
vector<int> adj1[N], adj2[N];
ll bitQnt[N], bitSum[N];
int maxVert[N];

ll sum (int p, ll *bit) {
	ll r = 0;
	for (; p >= 1; p-=p&-p)
		r += bit[p];
	return r;
}

void add (int p, ll v, ll *bit) {
	for (; p <= q; p+=p&-p)
		bit[p] += v;
}

pii farVert (int v, int p, int d, vector<int> *adj) {
	pii r = {v, d};
	for (int u : adj[v])
		if (u != p) {
			pii now = farVert (u, v, d+1, adj);
			if (now.y > r.y)
				r = now;
		}
		
	return r;
}

int dfs (int v, int p, int d, vector<int> *adj) {
	int r = 0;
	for (int u : adj[v])
		if (u != p)
			r = max (r, dfs (u, v, d+1, adj)+1);
		
	maxVert[v] = max (maxVert[v], max (r, d));
// 	printf ("Vert %d: %d vs [%d]\n", v, max(r,d), maxVert[v]);
	
	return r;
}

int comp (int v, int p, vector<int> *adj) {
	int r = 0;
	for (int u : adj[v])
		if (u != p)
			r = max (r, comp (u, v, adj)+1);
	return r;
}

int main () {
	while (scanf ("%d %d", &n, &q) != EOF) {
		// Clear
		int nq = max (n, q);
		for (int i = 1; i <= nq; i++) {
			qnt1[i] = qnt2[i] = bitSum[i] = bitQnt[i] = 0;
			adj1[i].clear(); adj2[i].clear();
			maxVert[i] = 0;
		}
		
		// Adj
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj1[u].push_back (v);
			adj1[v].push_back (u);
		}
		
		for (int i = 1; i < q; i++) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj2[u].push_back (v);
			adj2[v].push_back (u);
		}
		
		if (q == 1) {
			for (int i = 1; i <= n; i++)
				adj1[i].swap (adj2[i]);
			swap (n, q);
		}
// 		for (int i = 1; i <= q; i++) {
// 			printf ("Adj of %d\n", i);
// 			for (int u : adj2[i])
// 				printf ("%d ", u);
// 			putchar ('\n');
// 		}
				
		// Dist of each vert
		int farV = farVert (1, 1, 0, adj1).x;
		dfs (farV, farV, 0, adj1);
		farV = farVert (farV, farV, 0, adj1).x;
		dfs (farV, farV, 0, adj1);
// 		for (int i = 1; i <= n; i++) {
// 			if (comp (i, i, adj1) != maxVert[i]) {
// 				printf ("OLHA AI!!!\n");
// 				return 0;
// 			}
// 			else
// 				printf ("%d\t", i);
// 			if (i%10 == 0) putchar ('\n');
// 		}
		for (int i = 1; i <= n; i++) {
			qnt1[maxVert[i]]++;
			maxVert[i] = 0;
		}
		
		
		farV = farVert (1, 1, 0, adj2).x;
		dfs (farV, farV, 0, adj2);
		farV = farVert (farV, farV, 0, adj2).x;
// 		printf ("_______________\n");
		dfs (farV, farV, 0, adj2);
// 		for (int i = 1; i <= q; i++) {
// 			if (comp (i, i, adj2) != maxVert[i]) {
// 				printf ("OLHA AI ADJ2!!!\n");
// 				return 0;
// 			}
// 			else
// 				printf ("%d\t", i);
// 			if (i%10 == 0) putchar ('\n');
// 		}
		for (int i = 1; i <= q; i++) {
			qnt2[maxVert[i]]++;
			maxVert[i] = 0;
		}

		
//  		for (int i = 1; i <= n; i++)
//  			printf ("%d: %d\n", i, qnt1[i]);
//  		for (int i = 1; i <= q; i++)
//  			printf ("%d: %d\n", i, qnt2[i]);
		
		// Solution
		int mxDiam = 0;
		for (int i = 1; i <= q; i++)
			if (qnt2[i]) {
				mxDiam = max (mxDiam, i);
				add (i, qnt2[i]*1LL*i, bitSum);
				add (i, (ll)qnt2[i], bitQnt);
			}
			
		for (int i = n; i > 0; i--)
			if (qnt1[i]) {
				mxDiam = max (mxDiam, i);
				break;
			}
		
		ll ans = 0;
		if (n == 1) {
			if (q == 1)
				ans = 1;
			ll qntLow = sum (mxDiam-2, bitQnt);
			ll qntOk = sum (q, bitQnt)-qntLow;
			ans += qntLow * mxDiam;
			ans += qntOk * 1;
			ans += sum (q, bitSum) - sum (mxDiam-2, bitSum);
		}
		else
			for (int i = 1; i <= n; i++)
				if (qnt1[i]) {
					ll now = 0;
					ll qntLow = sum (mxDiam-i-2, bitQnt);
					ll qntOk = q-qntLow;
					now += qntLow * mxDiam;
					
					now += qntOk * (i+1);
					now += sum (q, bitSum) - sum (mxDiam-i-2, bitSum);
					
					ans += qnt1[i]*now;
//  					printf ("%d: %lld\n", i, ans);
				}
			
		printf ("%.3Lf\n", (ld)ans/(n*1LL*q));
	}

	return 0;
}
