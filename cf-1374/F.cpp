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

const int N = 505;

int t, n;
int inp[N], inp_sorted[N], perm[N];
vector<pair<int, int>> seq;
map<int, vector<int>> val_perm;
set<int> values;
vector<int> ans;

void sw(int pos) {
	swap(seq[pos], seq[pos+1]);
	swap(seq[pos], seq[pos+2]);
	ans.push_back(pos);
}

pii count_inv() {
	pii qnt_inv = {0, 0};
	vector<pii> aux;
	for(pii p : seq)
		aux.push_back(p);
	for(int i = 1; i <= n; i++)
		for(int j = n-1; j >= i; j--) {
			if(aux[j].x > aux[j+1].x)
				swap(aux[j].x, aux[j+1].x), qnt_inv.x++;
			if(aux[j].y > aux[j+1].y)
				swap(aux[j].y, aux[j+1].y), qnt_inv.y++;
		}

	return qnt_inv;
}

void prt(bool value) {
	for(int i = 1; i <= n; i++)
		printf("%d%c", value ? seq[i].y : seq[i].x, " \n"[i==n]);
}

int main () {
	scanf("%d", &t);
	while(t--) {
		seq.clear();
		val_perm.clear();
		ans.clear();
		values.clear();

		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &inp[i]);
			inp_sorted[i] = inp[i];
			values.insert(inp[i]);
		}
		sort(inp_sorted+1, inp_sorted+n+1);
		for(int i = 1; i <= n; i++) {
			int v = inp_sorted[i];
			if(val_perm.count(v) == 0)
				val_perm[v] = { i };
			else
				val_perm[v].push_back(i);
		}
		for(auto piv : val_perm) {
			sort(ALL(val_perm[piv.x]));
			reverse(ALL(val_perm[piv.x]));
		}
		seq.push_back({-1, -1});
		for(int i = 1; i <= n; i++) {
			seq.push_back({val_perm[inp[i]].back(), inp[i]});
			val_perm[inp[i]].pop_back();
		}

		pii qnt_inv = count_inv();
		if(qnt_inv.y%2 == 1 and LEN(values) == n) {
			printf("-1\n");
			continue;
		}

		qnt_inv = count_inv();
		if(qnt_inv.y%2 == 1) {
			// Minimum operations to put two equal values together.
			bool ok = false;
			for(int dist = 1; dist < n and !ok; dist++)
				for(int i = 1; i <= n-dist and !ok; i++) 
					if(seq[i].y == seq[i+dist].y) {
						if(dist > 1) {
							int pos = i;
							while(seq[pos].y != seq[pos+1].y and
									(pos == 1 or seq[pos-1].y != seq[pos].y)) {
								sw(max(1, pos-1));
								++pos;
							}
						}
						ok = true;
					}
		}

		qnt_inv = count_inv();
		if(qnt_inv.y%2) {			
			// Add or remove one invertion.
			bool ok = false;
			for(int i = 1; i <= n-3; i++)
				if(seq[i].y == seq[i+1].y) {
					swap(seq[i].x, seq[i+1].x);
					sw(i); sw(i);
					sw(i+1); sw(i+1);
					ok = true;
					break;
				}
			if(!ok)
				for(int i = n; i > n-2; i--)
					if(seq[i].y == seq[i-1].y) {
						swap(seq[i].x, seq[i-1].x);
						// printf("i = %d\n", i);
						if(i-3 < 1) sw(i-1), ++i;
						sw(i-3); sw(i-3);
						sw(i-2); sw(i-2);
						break;
					}
		} else if(qnt_inv.x%2) {
			for(int i = 1; i < n; i++)
				if(seq[i].y == seq[i+1].y) {
					swap(seq[i].x, seq[i+1].x);
					break;
				}
		}
		qnt_inv = count_inv();
		// Bubblesort
		for(int i = 1; i <= n; i++)
			for(int j = n-2; j >= i; j--) {
				int mini = min(min(seq[j].x, seq[j+1].x), seq[j+2].x);
				if(seq[j+2].x == mini)
					sw(j);
				while(j == i and seq[j].x != mini)
					sw(j);
			}
		qnt_inv = count_inv();
		printf("%d\n", LEN(ans));
		for(int i = 0; i < LEN(ans); i++) {
			printf("%d", ans[i]);
			if(i < LEN(ans)-1) putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}
