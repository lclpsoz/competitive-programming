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


int mdc(int a, int b) {
	if(b==0) return a;
	return mdc(b, a%b);
}

int mmc(int a, int b) {
	return (a*b)/mdc(a,b);
}

int main () {
	int n, b, k, m;
	int tt = 100;
	while(tt--) {
		vector<int> digits;
		int qnt[15];
		scanf("%d %d %d %d", &n, &b, &k, &m);
		memset(qnt, 0, sizeof qnt);
		for(int i = 0; i < n; i++) {
			int val;
			scanf("%d", &val);
			qnt[val]++;
		}

		for(int i = 1; i <= 9; i++)
			if(qnt[i]) digits.push_back(i);

		int axMmc = 1;
		vector<int> stCycle(12, -1);
		vector<int> szCycle(12, -1);
		for(int d : digits) {
			int now = d%m;
			int q = 0;
			vector<int> bef;
			for(int i = 0; i <= 100; i++) bef.push_back(0);
			do {
				++q;
				bef[now] = q;
				now = (now*10)%m;
			} while(bef[now] == 0);
			printf("Cycle: m = %d, %d -> %d, sz = %d\n", m, bef[now], q, q-bef[now]+1);
			stCycle[d] = bef[now];
			szCycle[d] = q-bef[now]+1;
			axMmc = mmc(q, axMmc);
			// if(m == 92)
			// 	printf("  ||%d %d\n", d, axMmc);
		}
		map<vector<int>, int> mp;
		int qNow = 0;
		vector<int> vec = digits;
		mp[{1, 2}] = -1;
		mp.count({1, 2});
		mp[vec] = 1;
		for(int i = 2;; i++) {
			printf("%2d: ", i);
			for(int j = 0; j < len(vec); j++) {
				vec[j] = (vec[j]*10)%m;
				printf("%d ", vec[j]);
			}
			putchar('\n');

			if(mp.count(vec)) {
				qNow = i;
				break;
			} else
				mp[vec] = i;
		}
		printf("%d -> %d\n", mp[vec], qNow-1);
		// printf("%d: %d\n", m, axMmc);
	}


	return 0;
}
