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

int comp, n;
int teste = 1;
vector<int> sorv_st[10100], sorv_en[10100];
vector<pii> ans;
set<int> now;

int main () {
	while(scanf("%d %d", &comp, &n), comp) {
		ans.clear();
		for(int i = 0; i < n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			sorv_st[u].push_back(i);
			sorv_en[v].push_back(i);
		}
		int st = -1;
		for(int i = 0; i <= comp; i++) {
			for(int v : sorv_st[i])
				now.insert(v);
			if(st == -1 and len(now))
				st = i;
			for(int v : sorv_en[i])
				now.erase(v);
			if(st != -1 and !len(now)) {
				ans.push_back({st, i});
				st = -1;
			}
			sorv_st[i].clear(), sorv_en[i].clear();
		}
		if(st != -1)
			ans.push_back({st, comp});
		printf("Teste %d\n", teste++);
		for(auto p : ans)
			printf("%d %d\n", p.x, p.y);
		putchar('\n');
	}

	return 0;
}
