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

int arr[1011];
int func[1011];

int main () {
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) arr[i] = i, func[i] = i;
	while(q--) {
		int opt;
		scanf("%d", &opt);
		if(opt == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			// printf("%d %d %d %d\n", arr[1], arr[2], func[1], func[2]);
			swap(func[x], func[y]);
			arr[func[x]] = x;
			arr[func[y]] = y;
		} else {
			int x;
			scanf("%d", &x);
			int p = arr[x];
			int ans = 0;
			// printf("1, 2: %d %d\n", arr[1], arr[2]);
			while(p != x) p = arr[p], ++ans;
			printf("%d\n", ans);
		}
	}

	return 0;
}
