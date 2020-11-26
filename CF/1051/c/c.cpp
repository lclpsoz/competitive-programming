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



int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vi vec(n);
	map<int, int> qq;
	for(int &v : vec) {
		cin >> v;
		qq[v]++;
	}
	int uniq = 0;
	bool mult_l2 = 0;
	for(int v : vec) {
		uniq += qq[v]==1;
		mult_l2 = mult_l2 or qq[v] > 2;
	}
	
	if(uniq%2 == 0) {
		cout << "YES\n";
		bool ax = 0;
		map<int, char> mp_c;
		for(auto &[v, q] : qq)
			if(q > 1)
				mp_c[v] = 'A';
		for(int v : vec)
			if(qq[v]==1) {
				cout << (char)('A'+ax);
				ax = !ax;
			}
			else
				cout << mp_c[v];
		cout << '\n';
	}
	else if(!mult_l2)
		cout << "NO\n";
	else {
		cout << "YES\n";
		bool ax = 0;
		map<int, char> mp_c;
		mult_l2 = 0;
		for(auto &[v, q] : qq) {
			if(q == 1) {
				mp_c[v] = 'A' + ax;
				ax = !ax;
			}
			else if(!mult_l2 and q > 2) {
				mult_l2 = true;
				mp_c[v] = 'B';
			}
			else
				mp_c[v] = 'A';
		}
		for(int v : vec) {
			cout << mp_c[v];
			if(qq[v] > 1 and mp_c[v] == 'B')
				mp_c[v] = 'A';
		}

		cout << '\n';
	}


	return 0;
}
