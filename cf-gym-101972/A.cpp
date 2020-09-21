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

bool special(ll a)
{
	if(a == 0) return false;
	if(abs(a) <= 10) return true;
	if(a % 10) return false;
	return special(a / 10);
}

ll nxt(ll a)
{
	ll n = 1;
	if(a < 0) n = -1;
	a = abs(a);
	ll b = a;
	while(b)
	{
		b /= 10;
		n *= 10;
	}
	n /= 10;
	while(a >= 10)
		a /= 10;
	n *= a + 1;
	return n;
}

void solve(ll a, ll b, bool s = true)
{
	if(special(a) && special(b))
		cout << a << " x " << b;
	else if(special(a))
	{
		ll c = nxt(b);
		cout << a << " x " << c << (s ? " - " : " + "), solve(a, c - b, !s);
	}
	else if(special(b))
	{
		ll c = nxt(a);
		cout << c << " x " << b << (s ? " - " : " + "), solve(c - a, b, !s);
	}
	else
	{
		ll c = nxt(a);
		ll d = nxt(b);
		cout << c << " x " << d << (s ? " - " : " + ");
		solve(c, d - b, !s); cout << (s ? " - " : " + ");
		solve(c - a, d, !s); cout << (s ? " + " : " - ");
		solve(c - a, d - b, s);
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		solve(a, b);
		cout << endl;
	}

	return 0;
}
