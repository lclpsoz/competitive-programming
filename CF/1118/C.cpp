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

int n;
int qnt[1010];
int mat[22][22];
vector<int> use;

void no () {
	printf ("NO\n");
	exit (0);
}

int main () {
	scanf ("%d", &n);
	
	for (int i = 0; i < n*n; i++) {
		int x;
		scanf ("%d", &x);
		qnt[x]++;
	}
	
	if (n&1) {
		vector<int> two;
		int one = -1;
		for (int i = 1; i <= 1000; i++) {
			if (qnt[i]&1) {
				if (one != -1)
					no ();
				one = i;
				qnt[i]--;
			}
			while (qnt[i] >= 4) {
				use.push_back (i);
				qnt[i] -= 4;
			}
			while (qnt[i] >= 2) {
				two.push_back (i);
				qnt[i] -= 2;
			}
		}
		while (len (use) > ((n/2) * (n/2))) {
			two.push_back (use.back());
			two.push_back (use.back());
			use.pop_back ();
		}
		
		if (len (use) != ((n/2) * (n/2)) or len (two) != (n-1)) no();
		
		mat[n/2 + 1][n/2 + 1] = one;
		for (int i = 1; i <= n/2; i++)
			for (int j = 1; j <= n/2; j++) {
				mat[i][j] = mat[n-i+1][j] = mat[i][n-j+1] = mat[n-i+1][n-j+1] = use.back();
				use.pop_back ();
			}
			
		for (int i = 1; i <= n/2; i++) {
			mat[i][n/2 + 1] =  mat[n-i+1][n/2 + 1] = two.back();
			two.pop_back ();
		}	
		for (int i = 1; i <= n/2; i++) {
			mat[n/2 + 1][n-i+1] = mat[n/2 + 1][i] = two.back();
			two.pop_back ();
		}					
	} else {
		for (int i = 1; i <= 1000; i++)
			if (qnt[i]%4 != 0) no ();
			else
				while (qnt[i]) {
					use.push_back (i);
					qnt[i] -= 4;
				}
		for (int i = 1; i <= n/2; i++)
			for (int j = 1; j <= n/2; j++) {
				mat[i][j] = mat[n-i+1][j] = mat[i][n-j+1] = mat[n-i+1][n-j+1] = use.back();
				use.pop_back ();
			}
	}
	printf ("YES\n");
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf ("%d%c", mat[i][j], " \n"[j==n]);
	
	return 0;
}