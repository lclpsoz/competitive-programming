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

void test() {
	vi amnt(10);
	for(int i = 0; i <= 9; i++)
		for(int j = 0; j <= 9; j++)
			amnt[(i*j)%10]++;
	cout << "All pairs:\n";
	for(int i = 0; i <= 9; i++)
		cout << i << ": " << amnt[i] << '\n';
	amnt = vi(10);
	cout << "Squares:\n";
	for(int i = 0; i <= 9; i++) {
			amnt[(i*i)%10]++;
			cout << i << ": " << (i*i)%10 << '\n';
	}
	cout << "\n_\n";
	for(int i = 0; i <= 9; i++)
		cout << i << ": " << amnt[i] << '\n';

	cout << "All pairs with *2:\n";
	amnt = vi(10);
	for(int i = 0; i <= 9; i++)
		for(int j = 0; j <= 9; j++)
			amnt[(2*i*j)%10]++;
	for(int i = 0; i <= 9; i++)
		cout << i << ": " << amnt[i] << '\n';

	cout << "All pairs i%2 == 0 with *2:\n";
	amnt = vi(10);
	for(int i = 0; i <= 8; i+=2)
		for(int j = 0; j <= 9; j++)
			amnt[(2*i*j)%10]++;
	for(int i = 0; i <= 9; i++)
		cout << i << ": " << amnt[i] << '\n';
}

vi ans(100, 1001);

vi _solve(string &inp, vi n, int sz, int p) {
	bool ok = false;
	int st = 0;
    vi bst = vi(LEN(n), 1010);
	if(p >= sz)
		st += p-sz+1;
	int lst = min(p, sz-1);
	// cout << "st, lst = " << st << ", " << lst << '\n';
	if(p == LEN(inp))
        return n;
	else if(p >= sz) {
		int sum = 0;
		for(int i = st; i <= lst; i++)
			sum = (sum+(n[i]*n[p-i])%10)%10;
		cout << "      p = " << p << ", sum = " << sum << '\n';
		if(sum == inp[p] and LEN(_solve(inp, n, sz, p+1)))
			return n;
        else
            return {};
	} else {
		int sum = 0;
		for(int i = st+1; i < lst; i++) {
			// cout << "|" << i << ", " << p-i << '\n';
			sum = (sum+(n[i]*n[p-i])%10)%10;
		}
		// cout << "p = " << p << ", st, lst = " << st << ", " << lst << '\n';
		// cout << "sum = " << sum << '\n';
		for(int i = p==sz-1; i <= 9; i++) {
			n[p] = i;
			bool verif = (((1+(p>0))*n[st]*n[lst])%10 + sum)%10==inp[p];
            // cout << "  p = "<<p<<", i = " << i << '\n';
			if(verif) {
                vi ret = _solve(inp, n, sz, p+1);
                if(LEN(ret)) {
				    cout << "    p = " << p << ", inp[p] = " << (char)(inp[p]+'0') << ", i = " << i << '\n';
                    // cout << "    VALID!\n";
                    for(int j = sz-1; j >= p; j--)
                        if(ret[j] < bst[j]) {
                            bst = ret;
                            break;
                        } else if(ret[j] > bst[j])
                            break;
                    ok = true;
                }
            }
		}
	}
    if(!ok)
        return {};
    else
	    return bst;
}

string solve(string inp) {
	vi n(50, 1001);
	ans = vi(50, 1000);
	if(inp == "0") return "0";
	for(char &c : inp) c -= '0';
	int sz = (LEN(inp)/2)+1;
	reverse(ALL(inp));
    n = _solve(inp, n, sz, 0);
	if(LEN(n) == 0)
		return "-1";

	// for(int i = 0; i < sz; i++)
	// 	cout << n[i];

	// ans = n;
	string ret = "";
	for(int i = sz-1; i >= 0; i--)
		ret +=  n[i]+'0';
	// cout << '\n';
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// cout << brute(123) << '\n';
	// test();
	// solve();
	// cin >> inp;
	map<string, int> mp;
	for(int i = 0; i < 1000; i++) {
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
	// for(int i = 0; i < 1000; i++) {
	// 	cout << "i = " << i << '\n';
	// 	string s = brute(i);
	// 	cout << "  s = " << s << '\n';
	// 	cout << "  solve = " << solve(s) << '\n';
	// 	cout.flush();
	// 	if(solve(s) != to_string(i)) {
	// 		cout << solve(s) << '\n';
	// 		cout << "here!\n";
	// 		cout.flush();
	// 		exit(0);
	// 	}
	// }

	return 0;
}
