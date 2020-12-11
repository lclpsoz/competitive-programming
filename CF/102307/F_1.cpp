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

using pll = pair<ll, ll>;
const int N = 2e5 + 10;

string s;
vector<int> vec;
int rht[N];

ll mdc(ll a, ll b) {
	if(b == 0) return a;
	return mdc(b, a%b);
}

ll mmc(ll a, ll b) {
	return (a*b)/mdc(a, b);
}

pll op(pll x, pll y, char c) {
	// cout << "op here!\n";
	// cout << x.x << ' ' << x.y << '\n';
	// cout << y.x << ' ' << y.y << '\n';
	ll m = mmc(x.y, y.y);
	// cout << "m = " << m << '\n';
	pll ret;
	if(c == '+')
		ret = {(x.x*m/x.y + y.x*m/y.y), m};
	else
		ret = {(x.x*m/x.y - y.x*m/y.y), m};
	m = mdc(ret.x, ret.y);
	ret = {ret.x/m, ret.y/m};
	if(ret.y < 0) ret.x*=-1, ret.y*=-1;
	return ret;
}

pll read(int l, int r) {
	// cout << "  read = " << l << ' ' << r << '\n';
	string ss = s.substr(l, r-l+1);
	int md = ss.find('/');
	// cout << "    md = " << md << '\n';
	return {(ll)stoi(ss.substr(0, md+1)), (ll)stoi(ss.substr(md+1, LEN(ss)-md-1))};
}

pll solve(int l, int r) {
	// cout << "  solve = " << l << ' ' << r << '\n';
	pll now = {0, 1};
	int lst = l;
	char lstOp = '+';
	for(int i = l; i <= r+1; i++)
		if(i == r+1 or s[i] == '+' or s[i] == '-') {
			// cout << "  i = " << i << '\n';
			if(s[lst] == '(') {
				i = rht[lst]+1;
				now = op(now, solve(lst+1, i-2), lstOp);
			}
			else
				now = op(now, read(lst, i-1), lstOp);
			// cout << "after!\n";
			lst = i+1;
			if(i <= r)
				lstOp = s[i];
			// cout << "    (" << l << ", " << r << ") = " << now.x << "/" << now.y << '\n';
		}

	return now;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// cout << mdc(1, 2) << '\n';
	// cout << mdc(2, 1) << '\n';
	while(cin >> s) {
		// pll x = read(0, 2);
		// cout << x.x << ' ' << x.y << '\n';
		
		for(int i = 0; i < LEN(s); i++)
			if(s[i] == '(')
				vec.push_back(i);
			else if(s[i] == ')'){
				rht[vec.back()] = i;
				vec.pop_back();
			}
		assert(vec.empty());
		pll ans = solve(0, LEN(s)-1);
		cout << ans.x << "/" << ans.y << '\n';
	}

	return 0;
}
