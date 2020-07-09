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

using pll = pair<ll, ll>;

int n;
vector<pll> inp;
set<int> st, st2;

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
	st2.clear();
	return now[k-1];
}

int qry_seq(ll k) {
	int dgs = 0;
	ll nxt = 1;
	ll jmp;
	for(int i = 1;;) {
		if(is_pow10((ll)i) and st2.count(i) == 0) {
			st2.insert(i);
			nxt *= 10;
			dgs++;
		}
		jmp = nxt-i-1;
		jmp *= 2;
		ll now, pa;
		printf("----\n");
		do {
			jmp/=2;
			pa = (((jmp+1)*jmp)/2);
			now = dgs*pa + (i-dgs)*(jmp);
			// printf("    jmp = %lld, now = %lld\n", jmp, now);
		}while(now >= k and jmp);
		if(k and now < k and now) {
			i += jmp;
			k -= now;
			i += jmp*dgs;
		}
		else if(k > seq_sz and now == 0 and i == nxt-1) {
			i++;
			k -= seq_sz;
			seq_sz += dgs+1;
		}
		if(k <= dgs)
			return qry_num(i, (int)k);
		// printf("  k = %lld\n", k);
		// k -= dgs;
	}
	// printf("-1\n");
}

int qry(ll k) {
	int dgs_new_num = 0;
	ll seq_sz = 1;
	ll nxt = 1;
	ll jmp;
	int p = 0;
	for(int lst_num = 1;;) {
		if(is_pow10((ll)lst_num) and st.count(lst_num) == 0) {
			dgs_new_num++;
			st.insert(lst_num);
			nxt *= 10;
		}
		jmp = nxt-lst_num-1;
		jmp *= 2;
		ll now, pa;
		printf("----\n");
		do {
			jmp/=2;
			pa = (((jmp+1)*jmp)/2);
			now = dgs_new_num*pa + (seq_sz-dgs_new_num)*(jmp);
			// printf("    jmp = %lld, now = %lld\n", jmp, now);
		}while(now >= k and jmp);
		printf("  dgs = %d, nxt = %d\n", dgs_new_num, nxt);
		// printf("  now = %lld\n", now);
		if(k and now < k and now) {
			lst_num += jmp;
			k -= now;
			seq_sz += jmp*dgs_new_num;
		}
		else if(k > seq_sz and now == 0 and lst_num == nxt-1) {
			lst_num++;
			k -= seq_sz;
			seq_sz += dgs_new_num+1;
		}
		// else {
		// 	if(lst_num > 1) {
		// 		k -= seq_sz;
		// 		seq_sz += dgs_new_num;
		// 	}
		// 	lst_num ++;
		// }
		printf("  lst_num = %d\n", lst_num);
		// printf("  seq_sz = %lld\n", seq_sz);
		// printf("  jmp = %lld\n", jmp);
		printf("  k = %lld\n", k);
		if(k <= seq_sz) {
			// printf("|k = %lld\n", k);
			int v = qry_seq(k);
			ll bef = inp[p].y;
			inp[p].y = v;
			if(p < n-1) {
				k += inp[p+1].y;
				inp[p+1].y -= bef;
				++p;
			} else
				return 1;
		}
		// k -= seq_sz;
	}
}

int main () {
	ll k;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		inp.push_back({i, x});
	}
	sort(inp.begin(), inp.end(), [&](pll a, pll b) { return a.y < b.y; });
	// printf("%lld %lld\n", inp[0].x, inp[0].y);
	for(int i = n-1; i > 0; i--)
		inp[i].y -= inp[i-1].y;
	qry(inp[0].y);

	sort(inp.begin(), inp.end());
	for(auto p : inp)
		printf("%lld\n", p.y);
	return 0;
}
