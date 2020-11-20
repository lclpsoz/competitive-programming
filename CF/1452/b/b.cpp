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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

bool valid(vi vec) {
	// if(vec[0] == 1 and vec[1] == 1 and vec[2] == 2)
		// cout << "HERE!\n";
	for(int i = 0; i < LEN(vec); i++) {
		int delta = 0;
		int mx =-1;
		for(int j = 0; j < LEN(vec); j++)
			if(i!=j)
				mx = max(vec[j], mx);
		for(int j = 0; j < LEN(vec); j++)
			if(i!=j)
				delta += mx-vec[j];
		// if(vec[0] == 1 and vec[1] == 1 and vec[2] == 2)
		// 	cout << i << ' ' << delta << '\n';
		if(delta > vec[i] or ((vec[i]-delta)%(LEN(vec)-1))) return false;
	}
	return true;
}

void brute() {
	vector<int> vec = {0, 0, 0,0};
	int mx = 9;
	int p = 0;
	set<vi> a;
	while(1) {
		if(valid(vec)) {
			vi ax = vec;
			sort(ALL(ax));
			a.insert(ax);
			// for( int v : vec)
			// 	cout << v << ' ';
			// cout << '\n';
		}
		p = 0;
		vec[p]++;
		while(p < LEN(vec)-1 and vec[p] > mx) {
			vec[p] = 0;
			vec[p+1]++;
			++p;
		}
		if(p == LEN(vec)-1 and vec.back() > mx) break;
	}
	for(vi vv : a) {
		for(int v : vv)
			cout << v << ' ';
		cout << '\n';
	}

	exit(0);
}

int mdc(int a, int b) {
	if(a==0) return b;
	return mdc(b%a, a);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// brute();

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi vec;
		ll sum = 0;
		int mx = -1;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			vec.push_back(x);
			sum += x;
			mx = max(mx, x);
		}

		ll base = sum;
		if(sum%(n-1))
			sum = ((sum+n-1)/(n-1))*(n-1);
		cout << max((mx*1LL*(n-1)), sum)-base << '\n';

	}

	return 0;
}
