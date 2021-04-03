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
const int MOD = 1e9 + 7;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

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

template<const int _mod>
struct modular
{
	int val;

	modular(ll x = 0LL)
	{
		val = int(x % _mod);
		if(val < 0) val += _mod;
	}

	modular operator + (const modular& o)
	{ return modular(val + o.val); }
	modular operator - (const modular& o)
	{ return modular(val - o.val); }
	modular operator * (const modular& o)
	{ return modular(val * 1LL * o.val); }
	modular operator / (const modular& o)
	{ return *this * fexp(o, _mod - 2); }

	bool operator == (const modular& o) { return val == o.val;}
	bool operator != (const modular& o) { return val != o.val;}

	friend istream& operator >> (istream& in, modular& o)
	{ ll x; in >> x; o = modular(x); return in; }
	friend ostream& operator << (ostream& out, const modular& o)
	{ out << o.val; return out; }
};


const int N = 2e5 + 10;
modular<MOD> fat[N];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	fat[0] = 1;
	for(int i = 1; i < N; i++)
		fat[i] = fat[i - 1] * i;

	int tt; cin >> tt;
	while(tt--)
	{
		int n; cin >> n;
		cout << fat[2*n-1] / (fat[n ] * fat[n - 1]) << endl;
	}


	return 0;
}
