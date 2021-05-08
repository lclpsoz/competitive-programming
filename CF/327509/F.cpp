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

struct fraction
{
    using base_t = ll;
    base_t a, b;
    fraction(base_t _a = 0, base_t _b = 1)
    {
        base_t g = gcd(_a, _b);
        a = _a / g;
        b = _b / g;
    }
    long double get()
    {
        return (long double)a / b;
    }
    fraction operator + (const fraction& f)
    {
        base_t g = gcd(b, f.b);
        g = b / g * f.b;    
        return fraction(a * (g / b) + f.a * (g / f.b), g);
    }
    fraction operator - (const fraction& f)
    {
        base_t g = gcd(b, f.b);
        g = b / g * f.b;
        return fraction(a * (g / b) - f.a * (g / f.b), g);
    }
    fraction operator * (const fraction& f)
    {
        return fraction(a * f.a, b * f.b);
    }
    fraction operator / (const fraction& f)
    {
        return fraction(a * f.b, b * f.a);
    }
	bool operator < (const fraction& f) const
    {
        base_t g = gcd(b, f.b);
        g = b / g * f.b;
		return a * (g / b) < f.a * (g / f.b);
    }
	bool operator <= (const fraction& f) const
    {
        base_t g = gcd(b, f.b);
        g = b / g * f.b;
		return a * (g / b) <= f.a * (g / f.b);
    }
    friend ostream& operator << (ostream& out, const fraction& f)
    { out << f.a << '/' << f.b; return out; }
};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vector<pair<int, int>> drone(n);
	for (int i = 0; i < n; i++) {
		int x, v;
		cin >> x >> v;
		drone[i] = {x, v};
	}

	set<pair<fraction, pii>> st;
	
	auto boom = [&](int l, int r)
	{
		if(l == -1 || r == -1 || drone[l].second <= drone[r].second)
			return;
		int d = drone[r].first - drone[l].first;
		int v = drone[l].second - drone[r].second;
		st.insert({fraction(d, v), pii(l, r)});
	};

	for (int i = 1; i < n; i++)
		boom(i - 1, i);

	vector<bool> crash(n, false);
	vi lft(n), rgh(n);
	iota(ALL(lft), -1);
	iota(ALL(rgh), 1);
	rgh[n - 1] = -1;

	fraction t;

	while(!empty(st))
	{
		auto now = st.begin()->first;
		auto [a, b] = st.begin()->second;
		st.erase(st.begin());
		
		if(crash[a] || crash[b])
		{
			continue;
		}

		assert(t <= now);
		t = now;

		// cout << a + 1 << " crashed with " << b + 1 << " at " << now << endl;
		crash[a] = crash[b] = true;
		boom(lft[a], rgh[b]);
		
		if(lft[a] != -1) rgh[lft[a]] = rgh[b];
		if(rgh[b] != -1) lft[rgh[b]] = lft[a];
	}

	cout << count(ALL(crash), false) << endl;
	for(int i = 0; i < n; i++)
		if(!crash[i]) cout << i + 1 << ' ';

	return 0;
}
