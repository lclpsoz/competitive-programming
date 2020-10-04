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

const int N = 2e5 + 10;

int n;
int a[N], b[N];
int mp[N];

int main () {
	mt19937 rng((llu)chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int val_now = -1;
	int max_seq = 0;
	int seq_now = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(val_now == a[i]) {
			seq_now++;
		} else {
			seq_now = 1;
			val_now = a[i];
		}
		max_seq = max(seq_now, max_seq);
	}
	vector<int> vals;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		mp[x]++;
		vals.push_back(x);
	}
	bool ans = false;
	for(int q = 0; !ans and q < 100; q++) {
		ans = true;
		shuffle(ALL(vals), rng);
		int l = 0, r = LEN(vals)-1;
		for(int i = 1; i <= n; i++) {
			if(a[i] == vals[l] and a[i] == vals[r]) {
				ans = false;
				break;
			} else if(a[i] == vals[r]) {
				b[i] = vals[l++];
			} else {
				b[i] = vals[r--];
			}

			// if(mp[a[i]]) {
			// 	b[i] = a[i];
			// 	mp[a[i]]--;
			// }
		}
	}
	// for(int i = 1; i <= n; i++)
	// 	while(mp[i]) {
	// 		vals.push_back(i);
	// 		mp[i]--;
	// 	}
	if(!ans) {
		cout << "No\n";
		exit(0);
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++)
		cout << b[i] << " \n"[i==n];


	return 0;
}
