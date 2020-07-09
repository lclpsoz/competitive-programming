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

const int INF = 1e9 + 100;
const int N = 1e5 + 10;

int n, b;
int v[N], p[N];
vector<pair<double, int>> vec;
unordered_map<int, int> pd[N];

int solve(int pos, int money) {
	if(money < 0) return -INF;
	if(pos == n) return 0;
	if(pd[pos].count(money) == 0)
		pd[pos][money] = -1;
	int &ret = pd[pos][money];
	ret = max(ret, solve(pos, money - p[pos]) + v[pos]);

}

int main () {
	scanf("%d %d", &n, &b);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for(int i = 0; i < n; i++)
		vec.push_back({(double)p[i]/v[i], i});
	sort(vec.begin(), vec.end());
	ld money = b;
	int qntInt = 0;
	ld qnt = 0;
	for(int pos = 0; pos < n and b > 0; pos++) {
		int i = vec[pos].y;
		// printf("%d\n", i);
		if(p[i] <= b) {
			b -= p[i];
			qntInt += v[i];
		} else
			qnt = ((double)b/p[i]) * v[i];
	}
	qnt += qntInt;
	// printf("qnt = %Lf\n", qnt);
	for(int ans = 1;; ans++) {
		// printf("ans = %lld, pa = %lld\n", ans, (ans*(ans-1))/2);
		if(cmp((ans*(ans+1))/2, qnt) == 1) {
			// printf("[%lld]\n", ans);
			printf("%d\n", ans-1);
			exit(0);
		}
	}

	return 0;
}
