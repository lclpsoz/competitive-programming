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

	vector<int> vec;
	for(int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		int pos = s.find('.');
		// cout << s << " " << pos << " " << stoi(s) << '\n';
		int v = 0;
		if(pos != string::npos) {
			// cout << (s.substr(0, pos)+s.substr(pos+1, LEN(s)-pos-1)) << '\n';
			v = stoi(s.substr(0, pos)+s.substr(pos+1, LEN(s)-pos-1));
		} else
			v = stoi(s)*10;
		// cout << v << '\n';
		vec.push_back(v);
	}
	for(int i = 0; i < (1<<4); i++) {
		int sum = 0;
		for(int j = 0; j < 4; j++)
			if((1<<j)&i)
				sum += vec[j];
			else
				sum -= vec[j];
		if(sum == 0) {
			cout << "YES\n";
			exit(0);
		}		
	}

	cout << "NO\n";

	return 0;
}
