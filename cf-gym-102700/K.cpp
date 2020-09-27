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

string s1, s2;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	cin >> s1 >> s2;
	int posInt = 0;
	for(int i = 0; i < LEN(s1); i++) {
		if(s1[i] >= '0' and s1[i] <= '9')
			break;
		posInt++;
		if(s1[i] > s2[i]) {
			cout << ">\n";
			exit(0);
		} else if (s1[i] < s2[i]) {
			cout << "<\n";
			exit(0);
		}
	}

	// Integers
	if(LEN(s1) > LEN(s2))
		cout << ">\n";
	else if(LEN(s1) < LEN(s2))
		cout << "<\n";
	else {
		for(int i = posInt; i < LEN(s1); i++) {
			if(s1[i] > s2[i]) {
				cout << ">\n";
				exit(0);
			} else if (s1[i] < s2[i]) {
				cout << "<\n";
				exit(0);
			}
		}
		cout << "=\n";
	}

	return 0;
}
