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
string str;
deque<char> dq;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.precision(10);
	cin >> n;
	cin >> str;
	for(int i = 0; i < LEN(str); i++) dq.push_back(str[i]);
	while(!dq.empty() and dq.front() == 'R') dq.pop_front();
	while(!dq.empty() and dq.back() == 'W') dq.pop_back();
	int qW = 0;
	for(int i = 0; i < LEN(dq); i++) qW += dq[i] == 'W';
	int ans = 0;
	for(int i = LEN(dq)-1; i > LEN(dq)-1-qW; i--)
		ans += dq[i] == 'R';
	cout << ans << '\n';

	return 0;
}
