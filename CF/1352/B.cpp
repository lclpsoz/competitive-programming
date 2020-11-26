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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int t;

int main () {
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		if((n%2 != k%2 and n < 2*k) or n < k or (k%2 == 0 and n%2 == 1))
			printf("NO\n");
		else {
			printf("YES\n");
			if(n == k)
				for(int i = 0; i < k; i++)
					printf("1%c", " \n"[i==k-1]);
			else {
				if(n%2 == k%2) {
					printf("%d", n-k+1);
					for(int i = 1; i < k; i++)
						printf(" 1");
					putchar('\n');
				} else {
					printf("%d", n-2*(k-1));
					for(int i = 1; i < k; i++)
						printf(" 2");
					putchar('\n');
				}
			}
		}
	}

	return 0;
}