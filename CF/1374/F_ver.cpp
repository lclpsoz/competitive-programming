#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int qnt, n, q;
int a[1010];

void sw(int pos, int *aux, bool ans) {
	// printf("  sw()!\n");
	// printf("    sw() pos = %d\n", pos);
	swap(aux[pos], aux[pos+1]);
	swap(aux[pos], aux[pos+2]);
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d", &q);
	qnt = 5;
	while(q--) {
		// if(q%1000 == 0)
			printf("q = %d\n", q);
		for(int i = 1; i <= qnt; i++)
			scanf("%d", &a[i]);
		for(int j = 1; j <= qnt; j++)
			printf("%d%c", a[j], " \n"[j==qnt]);
		scanf("%d", &n);
		printf("  n = %d\n", n);
		if(n == -1) continue;
		for(int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			sw(x, a, true);
		}
		for(int i = 1; i < qnt; i++)
			if(a[i] > a[i+1]) {
				for(int j = 1; j <= qnt; j++)
					printf("%d%c", a[j], " \n"[j==qnt]);
				printf("WA!\n");
				exit(0);
			}
	}

	return 0;
}
