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

int dp[205][205][808];
string s1, s2;
vector<char> ans;

int solve(int p1, int p2, int op) {
	if(p1 == LEN(s1)-1 and p2 == LEN(s2)-1 and !op)
		return 0;
	if(op > 800)
		return INF<int>;
	
	int &ret = dp[p1][p2][op];
	if(ret != -1) return ret;

	ret = solve(p1+(s1[p1] == '('), p2+(s2[p2] == '('), op+1) + 1;
	if(op)
		ret = min(ret, solve(p1+(s1[p1] == ')'), p2+(s2[p2] == ')'), op-1) + 1);
	return ret;
}

void recu(int p1, int p2, int op) {
	if(p1 == LEN(s1)-1 and p2 == LEN(s2)-1 and !op)
		return;
	if(op > 800)
		return;
	
	int &ret = dp[p1][p2][op];

	if(ret == solve(p1+(s1[p1] == '('), p2+(s2[p2] == '('), op+1) + 1) {
		ans.push_back('(');
		recu(p1+(s1[p1] == '('), p2+(s2[p2] == '('), op+1);
	}
	else {
		ans.push_back(')');
		recu(p1+(s1[p1] == ')'), p2+(s2[p2] == ')'), op-1);
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	memset(dp, -1, sizeof dp);

	cin >> s1 >> s2;
	s1 += '-';
	s2 += '-';
	solve(0, 0, 0);
	recu(0, 0, 0);
	for(char c : ans)
		cout << c;
	cout << '\n';

	return 0;
}
