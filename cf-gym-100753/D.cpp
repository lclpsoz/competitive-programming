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

const int DBG = 0;

bool nxt(vi &mask, int base) {
	mask[0]++;
	int p = 0;
	while(mask[p] == base) {
		mask[p++] = 0;
		if(p==LEN(mask)) return false;
		mask[p]++;
	}
	return true;
}

bool check(int n, int m, vpii carps, vi &mask, vi &order) {
	int area = 0;
	vi heights(n);
	// if(LEN(order) != 3) return false;
	if(DBG) {
		cout << "----------------\n";
		cout << "----------------\n";
	}
	if(DBG) {
		for(int id : order) {
			auto [w, h] = carps[id];
			if(mask[id] == 2) swap(w, h);
				cout << w << ", " << h << "| ";
		}
		cout << '\n';
	}
	for(int id : order) {
		auto [w, h] = carps[id];
		if(mask[id] == 2) swap(w, h);
		if(DBG)
			cout << "carp: " << w << ", " << h << '\n';
		int p = 0;
		for(int i = 0; i < n; i++)
			if(heights[i] < heights[p]) p = i;
		int mini = heights[p];
		if(p+w-1 >= n) return false;
		for(int i = p; i < p+w; i++)
			if(heights[i] != mini)
				return false;
			else
				heights[i]+=h;
		if(DBG) {
			cout << "\t\theights: ";
			for(int i = 0; i < n; i++)
				cout << heights[i] << " \n"[i==n-1];
		}
		area += h*w;
	}
	if(area != n*m) return false;
	return *max_element(ALL(heights)) == m and *min_element(ALL(heights)) == m;
	// set<pair<int, pii>> st;
	// st.insert({0, {1, m}});
	// for(int id : order) {
	// 	pii carp = carps[id];
	// 	if(mask[id] == 2) swap(carp.x, carp.y);
	// 	if(LEN(st) == 0) return false;
	// 	auto [h, pp] = *st.begin();
	// 	auto [x1, x2] = pp;
	// 	st.erase(st.begin());
	// 	if(h+carp.y > n) return false;
	// 	if(x1+carp.x-1 > m) return false;
	// 	if(h+carp.y < n) {
	// 		st.insert({h+carp.y, {x1, x1+carp.x-1}});
	// 		vector<pair<int, pii>> vec;
	// 		for(auto pt : st) vec.push_back(pt);
	// 		for(auto [hh, pt] : vec) {
	// 			auto [a1, a2] = pp;
	// 			if(hh == h+carp.y)
	// 		}
	// 	}
	// }
	// return LEN(st) == 0;
}

void yes() {
	cout << "yes\n";
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	int n_carp;
	vpii carps;

	cin >> n >> m;
	cin >> n_carp;
	for(int i = 1; i <= n_carp; i++) {
		int q, w, h;
		cin >> q >> w >> h;
		while(q--)
			carps.push_back({w, h});
	}

	vi mask(LEN(carps));
	int cnt = 0;
	do {
		vi order;
		for(int i = 0; i < LEN(carps); i++)
			if(mask[i])
				order.push_back(i);
		do {
			if(check(n, m, carps, mask, order))
				yes();
			++cnt;
		} while(next_permutation(ALL(order)));
	}while(nxt(mask, 3));
	// cout << "cnt = " << cnt << '\n';
	cout << "no\n";

	return 0;
}
