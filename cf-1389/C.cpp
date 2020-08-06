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

const int N = 2e5+10;

char str[N];
int qnt[10];

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(qnt, 0, sizeof qnt);
		scanf("%s", str);
		int maxi = 0;
		for(int i = 0; str[i] != '\0'; i++) {
			qnt[str[i]-'0']++;
		}
		for(int i = 0; i < 10; i++)
			maxi = max(maxi, qnt[i]);
		for(int f = 0; f < 10; f++)
			for(int s = 0; s < 10; s++)
				if(f != s) {
					bool sec = false;
					int now = 0;
					for(int i = 0; str[i] != '\0'; i++) {
						if(!sec and str[i]-'0' == f) {
							++now;
							sec = true;
						}
						else if(sec and str[i]-'0' == s) {
							++now;
							sec = false;
						}
					}
					if(now&1) --now;
					maxi = max(maxi, now);
				}
		printf("%d\n", (int)strlen(str)-maxi);
	}

	return 0;
}
