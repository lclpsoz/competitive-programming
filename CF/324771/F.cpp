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
		if(_a == 0 && _b == 0)
		{
			a = 0, b = 1;
		}
		else
		{
			base_t g = gcd(abs(_a), abs(_b));
			a = _a / g;
			b = _b / g;
			if(a < 0) a = -a, b = -b;
			if(b < 0) a = -a, b = -b;
		}
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
    bool operator != (const fraction& f)
    {
        return make_pair(a, b) != make_pair(f.a, f.b);
    }
    bool operator == (const fraction& f)
    {
        return make_pair(a, b) == make_pair(f.a, f.b);
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

	int n, m;
	cin >> n >> m;

	vpii a(m);
	for(auto& [x, y] : a) cin >> x >> y;
	sort(ALL(a));
	vpii t;
	for(int i = 1; i < m; i++)
	{
		ll x = a[i].first - a[i - 1].first;
		ll y = a[i].second - a[i - 1].second;
		t.emplace_back(x, y);
		// cout << "(" << x << ", " << y << ")" << " \n"[i == m - 1];
	}

	auto check = [&](fraction f, pair<ll,ll> i, pair<ll, ll> j)
	{
		// cout << f << " -> ";
		i.first *= f.a;
		i.second *= f.a;
		// cout << i.first << " // " << f.b << " e " << i.second << " // " << f.b << endl;
		if((i.first % f.b) || i.second % f.b)
			return false;
		i.first /= f.b;
		i.second /= f.b;
		return i == j;
	};

	for(int k = 0; k < n; k++)
	{
		if(m == 1) cout << "YES\n";
		else
		{
			vpii b(m);
			for(auto& [x, y] : b) cin >> x >> y;
			sort(ALL(b));

			bool ok = true;

			vector<fraction> d;

			for(int i = 1; i < m && ok; i++)
			{
				ll x = b[i].first - b[i - 1].first;
				ll y = b[i].second - b[i - 1].second;
				// cout << "(" << x << ", " << y << ")" << " \n"[i == m - 1];
				
				fraction now;
				if(t[i - 1].first)
					now = fraction(x, t[i - 1].first);
				else
					now = fraction(y, t[i - 1].second);

				if(!check(now, t[i - 1], {x, y}))
					ok = false;

				d.emplace_back(now);
			}

			for(auto f : d)
			{
				// cout << f << " ";
				if(f != d[0]) ok = false;
			}
			cout << (ok ? "YES\n" : "NO\n");
		}
	}

	return 0;
}
