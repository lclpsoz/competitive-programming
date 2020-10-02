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

vector<int> vals;

pii countBits(int p, vector<int> vec) {
	int bit = 1<<p;
	pii ret = {0, 0};
	for(int v : vec)
		if(bit&v) ret.y++;
		else ret.x++;
	return ret;
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cout << bitset<8>(x) << '\n';
		vals.push_back(x);
	}
	int ans = 0;
	ll total_inv = 0;
	for(int p = 30; p >= 0; p--) {
		int bit = 1<<p;
		vector<int> nxt;
		pair<ll, ll> qnt;
		pii total = countBits(p, vals);
		for(int v : vals)
			if(bit&v) { // bit 1
				total.y--;
				qnt.y += total.x;
			}
			else { // bit 0
				total.x--;
				qnt.x += total.y;
			}
		if(qnt.x < qnt.y) {
			// Have to invert
			ans ^= bit;
			swap(qnt.x, qnt.y);
			for(int &v : vals)
				v ^= bit;
		}
		total_inv += qnt.y;
		for(int v : vals)
			if(!(v&bit))
				nxt.push_back(v);
		for(int v : vals)
			if(v&bit)
				nxt.push_back(v);
		cout << "p = " << p << ", qnt = {" << qnt.x << ", " << qnt.y << "}\n";
		cout << "LEN(nxt) = " << LEN(nxt) << '\n';
		vals = nxt;
		nxt.clear();
	}
	cout << total_inv << ' ' << ans << '\n';

	return 0;
}
