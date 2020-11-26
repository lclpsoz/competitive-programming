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

bool is_pow10(ll x) {
	while(x%10 == 0) x/=10;
	return x == 1;
}

int qry_num(int x, int k) {
	vector<int> now;
	while(x > 0) {
		now.push_back(x%10);
		x /= 10;
	}
	reverse(now.begin(), now.end());
	// printf("    k = %lld\n", k);
	return now[k-1];
}

int qry_seq(ll k) {
	int dgs = 0;
	for(int i = 1;; i++) {
		dgs += is_pow10((ll)i);
		if(k <= dgs)
			return qry_num(i, (int)k);
		// printf("  k = %lld\n", k);
		k -= dgs;
	}
	printf("-1\n");
}

int qry(ll k) {
	int dgs_new_num = 0;
	ll seq_sz = 0;
	for(int lst_num = 1;; lst_num++) {
		dgs_new_num += is_pow10((ll)lst_num);
		seq_sz += dgs_new_num;
		if(k <= seq_sz) {
			printf("lst_num = %d\n", lst_num);
			printf("seq_sz = %d\n", seq_sz);
			return qry_seq(k);
		}
		k -= seq_sz;
		// printf("k = %lld\n", k);
	}
}

int main () {
	int n;
	ll k;
	scanf("%d", &n);
	while(n--){
		scanf("%lld", &k);
		printf("%d\n", qry(k));
	}

	return 0;
}
