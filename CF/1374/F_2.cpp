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


int a[600], b[600];
vector<int> vec;
int t, n;

void sw(int pos, int *aux, bool ans) {
	swap(aux[pos], aux[pos+1]);
	swap(aux[pos], aux[pos+2]);
	if(ans) vec.push_back(pos);
}

void bs() {
	for(int i = 1; i <= n; i++)
			for(int j = n-2; j >= i; j--) {
				if(a[j+2] < a[j+1] and a[j+2] < a[j]) {
					sw(j, a, true);
				}
				if(j == i and a[j] > a[j+1]) {
					sw(j, a, true);
					sw(j, a, true);
				}
			}
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d", &t);
	while(t--) {
		vec.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		int qntInv = 0;

		for(int i = 1; i <= n; i++)
			for(int j = n-1; j >= i; j--)
				if(b[j] > b[j+1]) {
					qntInv++;
					swap(b[j], b[j+1]);
				}
		if(qntInv%2) {
			sort(b+1, b+n+1);
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
			// for(int i = 1; i < n; i++) {
			// 	// printf("||val = %d, %d %d\n", val, a[i], a[i+1]);
			// 	if(a[i] == val and a[i-1] != val) {
			// 		swap(a[i], a[i+1]);
			// 		// printf("  HERE!!\n");
			// 		break;
			// 	}
			// }
		}
		// printf("INV = %d\n", qntInv%2);
		bs();
		if(qntInv%2) {
			bool check = false;
			for(int i = 1; i < n-2; i++)
				if(a[i] == a[i+1]) {
					swap(a[i+2], a[i+3]);
					vec.push_back(i);
					vec.push_back(i);
					vec.push_back(i+1);
					vec.push_back(i+1);
					check = true;
					break;
				}
			if(!check) {
				// assert(false);
				for(int i = n; i >= 3; i--)
					if(a[i] == a[i-1]) {
						swap(a[i-1], a[i-2]);
						vec.push_back(i-3);
						vec.push_back(i-3);
						vec.push_back(i-2);
						vec.push_back(i-2);
						break;
					}
			}
		}
		bs();
		if(a[n-1] > a[n] or a[n-2] > a[n-1])
			sw(n-2, a, true);
		if(a[n-1] > a[n] or a[n-2] > a[n-1])
			sw(n-2, a, true);
		// assert(!((a[n-1] > a[n] or a[n-2] > a[n-1])));
		// printf("----- st\n");
		// for(int i = 0; i < n; i++)
		// 	printf("%d%c", a[i], " \n"[i==n-1]);
		// printf("-----en\n");
		// if(a[n-2] > a[n-1] or a[n-3] > a[n-2] and qntInv%2 == 1)
		// 	sort(a+n-3, a+n);
		assert(LEN(vec) <= n*n);
		printf("%d\n", LEN(vec));
		if(LEN(vec)) printf("%d", vec[0]);
		for(int i = 1; i < LEN(vec); i++)
			printf(" %d", vec[i]);
		putchar('\n');
	}



	return 0;
}
