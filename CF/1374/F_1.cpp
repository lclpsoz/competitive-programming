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


int a[600], perm[600], b[600];
vector<int> vec;
int t, n;
map<int, vector<int>> mp;
vector<int> tmp;

void prt(int *aux) {
	return;
	printf("_____________________________\n");
	for(int i = 1; i <= n; i++)
		printf("%d%c", aux[i], " \n"[i==n]);
	printf("_____________________________\n");
}

void sw(int pos, int *aux, bool ans) {
	// printf("  sw(pos = %d)!\n", pos);
	swap(aux[pos], aux[pos+1]);
	swap(aux[pos], aux[pos+2]);
	if(ans) vec.push_back(pos);
}

void bs() {
	// printf("---------------- START BS ----------------\n");
	for(int i = 1; i <= n; i++)
			for(int j = n-2; j >= i; j--) {
				if(perm[j+2] < perm[j+1] and perm[j+2] < perm[j]) {
					sw(j, a, true);
					sw(j, perm, false);
				}
				if(j == i and perm[j] > perm[j+1]) {
					sw(j, a, true);
					sw(j, a, true);
					sw(j, perm, false);
					sw(j, perm, false);
				}
				// printf("......\n");
				// printf("perm:\n");
				// prt(perm);
				// prt(a);
				// printf("......\n");
			}
	// printf("---------------- END BS ----------------\n");
}

int countInv(int *data) {
	int qntInv = 0;
	int aux[600];
	for(int i = 1; i <= n; i++) aux[i] = data[i];
	for(int i = 1; i <= n; i++)
		for(int j = n-1; j >= i; j--)
			if(aux[j] > aux[j+1]) {
				qntInv++;
				swap(aux[j], aux[j+1]);
			}
	return qntInv;
}

void invForce() {
	if(countInv(perm)%2) {
			bool check = false;
			for(int i = 1; i < n-2; i++)
				if(a[i] == a[i+1] and a[i+2] != a[i+3]) {
					swap(a[i+2], a[i+3]);
					swap(perm[i+2], perm[i+3]);
					vec.push_back(i);
					vec.push_back(i);
					vec.push_back(i+1);
					vec.push_back(i+1);
					check = true;
					break;
				}
			if(!check) {
				// assert(false);
				for(int i = n; i >= 4; i--)
					if(a[i] == a[i-1] and a[i-2] != a[i-3]) {
						swap(a[i-2], a[i-3]);
						swap(perm[i-2], perm[i-3]);
						vec.push_back(i-3);
						vec.push_back(i-3);
						vec.push_back(i-2);
						vec.push_back(i-2);
						break;
					}
			}
		}
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d", &t);
	// printf("%d\n", t);
	while(t--) {
		// printf("================ START ================\n");
		vec.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			// printf("%d%c", a[i], " \n"[i==n]);
			b[i] = a[i];
		}
		sort(b+1, b+n+1);
		for(int i = 1; i <= n; i++) {
			if(mp.count(b[i]) == 0)
				mp[b[i]] = { i };
			else
				mp[b[i]].push_back(i);
		}
		// printf("PERM:\n");
		for(int i = 1; i <= n; i++) {
			perm[i] = mp[a[i]].back();
			// printf("%d%c", perm[i], " \n"[i==n]);
			mp[a[i]].pop_back();
		}
		// printf("  || 0. INVs = %d, %d\n", countInv(a), countInv(perm));
		mp.clear();
		if(countInv(a)%2) {
			int val = -1;
			for(int i = 1; i < n; i++) {
				// printf("| %d %d\n", b[i], b[i+1]);
				if(b[i] == b[i+1]) {
					val = b[i];
					break;
				}
			}
			if(val == -1) {
				printf("-1\n");
				continue;
			}
			if(countInv(a)%2 != countInv(perm)%2) {
				tmp.clear();
				// printf("val = %d\n", val);
				for(int i = 1; i <= n; i++) {
					if(a[i] == val and (LEN(tmp) == 0 or (i-tmp.back())%2 == 1)) {
						tmp.push_back(i);
						if(LEN(tmp)==2)
							break;

					}
				}
				// printf("%d\n", LEN(tmp));
				if(LEN(tmp) == 1) {
					// for(int i = 1; i <= n; i++)
					// 	printf("%d: %d\n", i, a[i]);
					for(int i = 1; i <= n; i++) {
						if(a[i] == val) {
							// printf("here!!\n");
							sw(min(i, n-2), a, true);
							sw(min(i, n-2), perm, false);
							break;
						}
					}
					tmp.clear();
					for(int i = 1; i <= n; i++) {
						// printf("%d: %d\n", i, a[i]);
						if(a[i] == val and (LEN(tmp) == 0 or (i-tmp.back())%2 == 1)) {
							tmp.push_back(i);
							if(LEN(tmp)==2)
								break;

						}
					}
				}
						// tmp.push_back(i);
				swap(perm[tmp[0]], perm[tmp[1]]);
			}
			// for(int i = 1; i < n; i++) {
			// 	// printf("||val = %d, %d %d\n", val, a[i], a[i+1]);
			// 	if(a[i] == val and a[i-1] != val) {
			// 		swap(a[i], a[i+1]);
			// 		// printf("  HERE!!\n");
			// 		break;
			// 	}
			// }
		}
		prt(a);
		// printf("perm:\n");
		prt(perm);
		bs();
		// printf("--------------------------------------------\n");
		prt(a);
		// printf("perm:\n");
		prt(perm);
		// printf("  || BS | 1. LEN = %d, INVs = %d\n", LEN(vec), countInv(a));
		invForce();
		prt(a);
		// printf("  || 2. LEN = %d, INVs = %d\n", LEN(vec), countInv(a));
		bs();
		prt(a);
		// printf("  || 3. BS | LEN = %d, INVs = %d\n", LEN(vec), countInv(a));
		// invForce();
		prt(a);
		// printf("  || 4. LEN = %d, INVs = %d\n", LEN(vec), countInv(a));
		// bs();
		prt(a);
		// printf("  || 5. BS | LEN = %d, INVs = %d\n", LEN(vec), countInv(a));
		prt(a);
		prt(perm);
		if(a[n-1] > a[n] or a[n-2] > a[n-1]) {
			sw(n-2, a, true);
			sw(n-2, perm, false);
		}
		prt(a);
		prt(perm);
		if(a[n-1] > a[n] or a[n-2] > a[n-1]) {
			sw(n-2, a, true);
			sw(n-2, perm, false);
		}
		prt(a);
		prt(perm);
		// printf("  || 6. INVs = %d\n", countInv(perm));
		// assert(!((a[n-1] > a[n] or a[n-2] > a[n-1])));
		// printf("----- st\n");
		// // for(int i = 1; i <= n; i++)
		// // 	printf("%d%c", a[i], " \n"[i==n]);
		// printf("-----en\n");
		// if(a[n-2] > a[n-1] or a[n-3] > a[n-2] and qntInv%2 == 1)
		// 	sort(a+n-3, a+n);
		// assert(LEN(vec) <= n*n);
		// assert(countInv(a)%2 == 0);
		printf("%d\n", LEN(vec));
		if(LEN(vec)) printf("%d", vec[0]);
		for(int i = 1; i < LEN(vec); i++)
			printf(" %d", vec[i]);
		putchar('\n');
	}

	return 0;
}
