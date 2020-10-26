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

string brute(int a) {
	string s = to_string(a);
	for(char &c : s)
		c -= '0';
	string ret = s+s;
	ret.pop_back();
	for(char &c : ret)
		c = 0;
	int n = LEN(s);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ret[i+j] = (ret[i+j]+(s[i]*s[j])%10)%10;

	for(char &c : ret)
		c += '0';
	return ret;
}

vi _solve(string &inp, vi n, int sz, int p) {
	int st = max(0, p-sz+1);
	int lst = min(p, sz-1);
	// for(int i = 0; i < 2*p; i++) cout << '|';
	// cout << "p = " << p << ", st = " << st << ", lst = " << lst << ", sz = " << sz << '\n';
	cout.flush();
	if(p == LEN(inp))
		return n;
	else if(p >= sz) {
		int sum = 0;
		for(int i = st; i <= lst; i++) {
			// cout << "---->>>> " << i << " " << p-i << '\n';
			sum = (sum + (n[i]*n[p-i])%10)%10;
		}
		// for(int i = 0; i < 2*p; i++) cout << '|';
		// cout << "    sum = " << sum << ", inp[p] = " << (char)('0'+inp[p]) << '\n';
		if(sum == inp[p] and LEN(_solve(inp, n, sz, p+1)))
			return n;
		else
			return {};
	}
	else {
		vi bst = {};
		for(n[p] = p == sz-1; n[p] <= 9; n[p]++) {
			int sum = 0;
			for(int i = st; i <= lst; i++)
				sum = (sum + (n[i]*n[p-i])%10)%10;

			// for(int i = 0; i < 2*p; i++) cout << '|';
			// cout << "  n[" << p << "] = " << n[p] << ", sum = " << sum << ", inp[p] = " << (char)(inp[p]+'0') << '\n';
			cout.flush();
			if(sum == inp[p]) {
				vi ret = _solve(inp, n, sz, p+1);
				if(LEN(ret)) {
					if(LEN(bst) == 0) bst = ret;
					else
						for(int i = sz-1; i > p; i--)
							if(ret[i] < bst[i]) {
								bst = ret;
								break;
							} else if(ret[i] > bst[i])
								break;
					// for(int i = sz-1; i >= 0; i--)
					// 	cout << bst[i] << " \n"[i==0];
				}
			}
		}
		// cout << "    LEN(bst) = " << LEN(bst) << '\n';
		cout.flush();
		return bst;
	}
}

string solve(string inp) {
	vi n(50, 1001);
	if(inp == "0")
		return "0";
	for(char &c : inp)
		c -= '0';
	int sz = (LEN(inp)/2)+1;
	reverse(ALL(inp));
    n = _solve(inp, n, sz, 0);
	if(LEN(n) == 0)
		return "-1";

	string ret = "";
	for(int i = sz-1; i >= 0; i--)
		ret += n[i]+'0';

	return ret;
}

void test_solve() {
	map<string, int> mp;
	for(int i = 0; i < 10000; i++) {
		string s = brute(i);
		if(mp.count(s) == 0) {
			mp[s] = i;
			string ss = solve(s);
			if(to_string(i) != ss) {
				cout << "WA in " << i << ", s = " << s << ", ss = " << ss << '\n';
				exit(0);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// test_solve();

	string inp;
	cin >> inp;
	cout << solve(inp) << '\n';

	return 0;
}
