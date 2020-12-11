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



int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.precision(10);

	int X, Y;
	cin >> X >> Y;
	
	int N;
	cin >> N;
	
	pii mm[X];
	for (int i = 0; i < X; i++)
		mm[i] = {Y, -1};
	
	map<int, bool> mp;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		mm[x].second = max(mm[x].second, y);
		mm[x].first = min(mm[x].first, y);
		mp[x] = true;
	}
	
	vector<int> pd_min(Y), pd_max(Y);
	for (int i = 0; i < X; i++) {
		if (mp[i] == true) {
			pd_min[mm[i].first]++;
			pd_max[mm[i].second]++;
		}
	}
	
	vector<ll> prefix_sum_min(Y), prefix_sum_max(Y);
	int count = 0;
	for (int i = 0; i < Y; i++) {
		if (i) {
			prefix_sum_min[i] = prefix_sum_min[i - 1] + 2 * count + 2 * pd_min[i - 1];
			count += pd_min[i - 1];
		}
		//prefix_sum_min[i] += pd_min[i];
		//cout << prefix_sum_min[i] << endl;
	}
	
	count = 0;
	for (int i = Y - 1; i >= 0; i--) {
		if (i < Y - 1) {
			prefix_sum_max[i] = prefix_sum_max[i + 1] + 2 * count + 2 * pd_max[i + 1];
			count += pd_max[i + 1];
		}
		//cout << prefix_sum_max[i] << endl;
	}
	
	long long r = 1e18;
	for (int i = 0; i < Y; i++)
		r = min(r, prefix_sum_min[i] + prefix_sum_max[i]);
	cout << (X - 1) + r << endl;
	
	//cout << pd_min[0] << " " << pd_min[1] << " " << pd_min[2] << endl;
	//cout << prefix_sum_min[3] << endl;
	return 0;
}
