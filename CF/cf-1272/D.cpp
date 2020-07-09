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

const int N = 2e5 + 10;

int n;
int a[N];
bool vis[N];

int main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	bool seq = false;
	bool used = false;
	int now = 0;
	int ans = 0;
	int lst = -1;
	int lstBef = -1;
	int bckp = 0;
	for(int i = 0; i < n; i++)
		if(!seq and !vis[i]) {
			seq = true;
			used = false;
			vis[i] = true;
			++now;
			lst = a[i];
		} else if(seq) {
			if(a[i] <= lst) {
				if(used) {
					seq = false;
					used = false;
					ans = max(ans, now);
					now = 0;
					i = bckp-1;
				} else {
					used = true;
					if(a[i] < lst and a[i] > lstBef) {
						// Remove the previous value
						bckp = i-1;
						lst = a[i];
					} else {
						bckp = i;
					}
				}
			} else {
				// printf("new = %d\n", a[i]);
				++now;
				lstBef = lst;
				lst = a[i];
				vis[i] = true;
			}
		}
	ans = max(ans, now);
	printf("%d\n", ans);

	return 0;
}
