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

int n;
bool vis[1010];

int main () {
	scanf("%d", &n);
	vector<pii> vec;
	for(int i = 0; i < n-1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(x > y) swap(x, y);
		vec.push_back({x, y});
	}
	sort(vec.begin(), vec.end());
	for(int i = 1; i < n; i++)
		if(vec[i-1].x < i or vec[i-1].y != n) {
			printf("NO\n");
			exit(0);
		}
	printf("YES\n");
	vector<int> nodes;

	int lft = 0;
	int p = 1;
	for(int i = 1; i < n; i++) {
		int val = vec[i-1].x;
		// printf("|%d\n", val);
		if(val > lft) {
			vis[val] = true;
			nodes.push_back(val);
			lft = val;
		} else {
			while(vis[p]) ++p;
			nodes.push_back(p);
			vis[p] = true;
		}
	}
	nodes.push_back(n);
	// printf("%d\n", len(nodes));
	for(int i = 0; i < n-1; i++) {
		// printf("acess: %d\n", i+1);
		printf("%d %d\n", nodes[i], nodes[i+1]);
	}

	return 0;
}
