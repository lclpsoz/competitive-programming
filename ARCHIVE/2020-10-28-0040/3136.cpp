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

int n;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	vi vec;
	bitset<101> msk;
	vi ram(101);

	cin >> n;
	while(n--) {
		string command;
		cin >> command;
		if(command.substr(0, 3) == "pus") {
			string v = command.substr(5);
			if(v[0] == 'R') {
				int pos = stoi(v.substr(1));
				assert(msk[pos]);
				vec.push_back(ram[pos]);
			} else
				vec.push_back(stoi(v));
		}
		else if(command.substr(0, 3) == "pop") {
			int pos = stoi(command.substr(5));
			ram[pos] = vec.back();
			msk[pos] = vec.back();
			vec.pop_back();
		}
		else if(command.substr(0, 3) == "pri") {
			assert(LEN(vec));
			cout << vec.back() << '\n';
			vec.pop_back();
		}
		else {
			assert(LEN(vec) >= 2);
			int x = vec.back();
			vec.pop_back();
			int y = vec.back();
			vec.pop_back();
			if(command.substr(0, 3) == "add")
				vec.push_back(x+y);
			else if(command.substr(0, 3) == "mul")
				vec.push_back(y*x);
			else if(command.substr(0, 3) == "div")
				vec.push_back(y/x);
			else if(command.substr(0, 3) == "sub")
				vec.push_back(y-x);
		}

	}

	return 0;
}
