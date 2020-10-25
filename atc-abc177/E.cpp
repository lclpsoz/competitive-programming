#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
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

const int N = 1e6 + 10;

bitset<N> not_prime;
int min_div_prime[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	for(int i = 2; i*i < N; i++)
		if(!not_prime[i])
			for(int j = i*i; j < N; j+=i) {
				not_prime[j] = 1;
				if(!min_div_prime[j])
					min_div_prime[j] = i;
			}
	for(int i = 2; i < N; i++)
		if(!not_prime[i] and !min_div_prime[i])
			min_div_prime[i] = i;

	
	int n;
	cin >> n;
	vector<int> vis(N, 0);
	string ans = "pairwise coprime";
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while(x > 1) {
			int p = min_div_prime[x];
			while(x%p == 0) x/=p;
			if(vis[p])
				ans = "setwise coprime";
			vis[p]++;
		}
	}
	for(int i = 2; i < N; i++)
		if(vis[i] == n) {
			cout << "not coprime\n";
			exit(0);
		}
	cout << ans << '\n';

	return 0;
}
