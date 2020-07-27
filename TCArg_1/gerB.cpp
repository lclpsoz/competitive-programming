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

vector<int> v;

int maxi(int l, int r) {
	int ret = -1;
	for(int i = l; i <= r; i++)
		ret = max(ret, v[i]);
	return ret;
}
int mini(int l, int r) {
	int ret = 1000000000;
	for(int i = l; i <= r; i++)
		ret = min(ret, v[i]);
	return ret;
}

int main () {
	int n = 1;
	// scanf("%d", &n);
	vector<int> ax;
	while(n < 100) {
		ll ans = 0;
		ax.clear(), v.clear();
		for(int i = 1; i <= n; i++) {
			v.push_back(i);
			ax.push_back(0);
		}
		do {
			for(int i = 0; i < n; i++)
				for(int j = i; j < n; j++) {
					ans += (maxi(i, j)-mini(i,j)) == (j-i);
					ax[j-i] += (maxi(i, j)-mini(i,j)) == (j-i);
				}
			// printf("!\n");
		} while(next_permutation(v.begin(), v.end()));
		printf("%d: %lld\n", n, ans);
		for(int i = 0; i < n; i++)
			printf(" %d: %d\n", i, ax[i]);
		++n;
	}

	return 0;
}
