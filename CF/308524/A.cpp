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

int fat[11];
string s;
ordered_set<int> st;
int solve(int n)
{
	if(n == 0) return 1;
	int c = int(s[n - 1] - '0');
	int p = (int)st.order_of_key(c);
	st.erase(c);
	return p * fat[n - 1] + solve(n - 1);
}

template<class base_t>
base_t fexp(base_t b, ll x)
{
	base_t ans(1);
	while(x)
	{
		if(x & 1LL) ans = ans * b;
		b = b * b;
		x >>= 1LL;
	}
	return ans;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(9);

	fat[0] = 1;
	for(int i = 1; i <= 10; i++)
		fat[i] = fat[i - 1] * i;

	int t; cin >> t;
	while(t--)
	{
		cin >> s;
		reverse(ALL(s));
		int n = LEN(s);
		for(char c : s) st.insert(c - '0');
		int p = fat[n] - solve(n);
		
		double ans = 0, a = 1;
		for(int i = 0; i < p; i++)
		{
			double now = a / fat[n];
			a += now;
			ans = now;
		}
		
		cout << fixed << ans << endl;
	}

	return 0;
}
