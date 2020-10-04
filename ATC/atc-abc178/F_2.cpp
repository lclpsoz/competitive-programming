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
bitset<N> vals_a;
bitset<N> past_value;
int a[N], b[N], c[N], c_shift[N];
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
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		vals_a[a[i]] = 1;
		if(val_now == a[i]) {
			seq_now++;
		} else {
			seq_now = 1;
			val_now = a[i];
		}
		max_seq = max(seq_now, max_seq);
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		mp[b[i]]++;
	}

	for(int i = 0; i < n; i++)
		if(mp[a[i]]) {
			c[i] = a[i];
			mp[a[i]]--;
		}

	vector<int> vals;
	for(int i = 1; i <= n; i++)
		while(vals_a[i] and mp[i]) {
			cout << "v = " << i << '\n';
			vals.push_back(i);
			mp[i]--;
		}
	reverse(ALL(vals));

	for(int i_not = 0; i_not < 2*n; i_not++) {
		int pos = i_not%n;
		int v = vals.back();
		if(c[pos] == 0 and past_value[v]) {
			c[pos] = v;
			vals.pop_back();
		}

		past_value[a[pos]] = 1;
	}
	cout << "c_here = ";
	for(int i = 0; i < n; i++)
		cout << c[i] << " \n"[i==n-1];
	assert(vals.empty());
	for(int i = 1; i <= n; i++)
		while(mp[i]) {
			vals.push_back(i);
			mp[i]--;
		}
	for(int i = 0; i < n; i++)
		if(c[i] == 0) {
			c[i] = vals.back();
			vals.pop_back();
		}
	for(int i = 0; i < n; i++) {
		c_shift[i] = c[(i+max_seq)%n];
		if(c_shift[i] == a[i])  {
			cout << "No\n";
			exit(0);
		}
	}

	cout << "Yes\n";
	for(int i = 0; i < n; i++)
		cout << c_shift[i] << " \n"[i==n-1];


	return 0;
}
