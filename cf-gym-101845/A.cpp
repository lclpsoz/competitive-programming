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

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

template<class base_t>
base_t inverse(base_t a, base_t m)
{
	base_t x = 0, y = 1;
	while(a > 0)
	{
		base_t t = m / a;
		m -= t * a; swap(a, m);
		x -= t * y; swap(x, y);
	}
	assert(m == 1);
	return x;
}

template<class base_t>
struct modular
{
	using mod_t = modular<base_t>;
	base_t val;
	static base_t mod;

	template<class T>
	inline base_t normalize(T n)
	{
		if(n >= mod || n < -mod)
			n = (T)(n % mod);
		if(n < 0)
			n = (T)(n + mod);
		return (base_t)n;
	}

	modular(){ val = 0;}
	template<class T> modular(T x = 0) { val = normalize(x);}
	template<class T> explicit operator T() { return static_cast<T>(val);}
	const base_t operator ()() const { return val;}

	mod_t operator + (const mod_t& o)
	{
		base_t a = val + o(); if(a >= mod) a -= mod; return mod_t(a);
	}
	mod_t operator - (const mod_t& o)
	{
		base_t a = val - o(); if(a < 0) a += mod; return mod_t(a);
	}
	mod_t operator * (const mod_t& o)
	{
		if(is_same<base_t, int>::value)
			return normalize((ll)val * (ll)o());
		if(is_same<base_t, ll>::value)
		{
			ll x = (ll)((long double)val * o() / mod);
			ll y = (ll)((long double)val * o() - x * mod);
			return y;
		}
		assert(true);
	}
	mod_t operator / (const mod_t& o) { return *this * inverse(o(), mod);}

	mod_t& operator += (const mod_t& o) { return *this = *this + o;}
	mod_t& operator -= (const mod_t& o)	{ return *this = *this - o;}
	mod_t& operator *= (const mod_t& o)	{ return *this = *this * o;}
	mod_t& operator /= (const mod_t& o)	{ return *this = *this / o;}

	template<class T>
	mod_t& operator += (const T& o) { return *this = *this + mod_t(o);}
	template<class T>
	mod_t& operator -= (const T& o) { return *this = *this - mod_t(o);}
	template<class T>
	mod_t& operator *= (const T& o) { return *this = *this * mod_t(o);}
	template<class T>
	mod_t& operator /= (const T& o) { return *this = *this / mod_t(o);}
	
	mod_t& operator ++ () { return *this += 1;}
	mod_t& operator -- () { return *this -= 1;}
	mod_t operator ++ (int) { mod_t old(val); *this += 1; return old;}
	mod_t operator -- (int) { mod_t old(val); *this -= 1; return old;}

	bool operator == (const mod_t& o) { return val == o();}
	bool operator != (const mod_t& o) { return val != o();}
	bool operator < (const mod_t& o) { return val < o();}
	bool operator > (const mod_t& o) { return val > o();}
	bool operator <= (const mod_t& o) { return val <= o();}
	bool operator >= (const mod_t& o) { return val >= o();}

	friend istream& operator >> (istream& in, mod_t& o)
	{
		ll x; in >> x; o = mod_t(x); return in;
	}

	friend ostream& operator << (ostream& out, const mod_t& o)
	{
		out << o(); return out;
	}
};

template<class T, class base_t>
modular<base_t> operator + (T a, const modular<base_t>& b) { return modular<base_t>(a) + b;}
template<class T, class base_t>
modular<base_t> operator - (T a, const modular<base_t>& b) { return modular<base_t>(a) - b;}
template<class T, class base_t>
modular<base_t> operator * (T a, const modular<base_t>& b) { return modular<base_t>(a) * b;}
template<class T, class base_t>
modular<base_t> operator / (T a, const modular<base_t>& b) { return modular<base_t>(a) / b;}

template<class T, class base_t>
bool operator == (T a, const modular<base_t>& b) { return a == b();}
template<class T, class base_t>
bool operator != (T a, const modular<base_t>& b) { return a != b();}
template<class T, class base_t>
bool operator < (T a, const modular<base_t>& b) { return a < b();}
template<class T, class base_t>
bool operator <= (T a, const modular<base_t>& b) { return a <= b();}
template<class T, class base_t>
bool operator > (T a, const modular<base_t>& b) { return a > b();}
template<class T, class base_t>
bool operator >= (T a, const modular<base_t>& b) { return a >= b();}

// template<class T>
// T& md = modular<T>::mod;

template<class T>
T modular<T>::mod(MOD);

template<class base_t, const int M, const int N>
struct matrix
{
	base_t **t;

	matrix(base_t c = 0)
	{
		t = new base_t*[M];
		for(int i = 0; i < M; i++)
		{
			t[i] = new base_t[N];
			for(int j = 0; j < N; j++)
				t[i][j] = 0;
		}
		for(int i = 0; i < min(M, N); i++)
			t[i][i] = c;
	}

	base_t* & operator [] (const int i) { return t[i];}

	matrix<base_t, M, N> operator + (const matrix<base_t, M, N>& o)
	{
		matrix<base_t, M, N> ans;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				ans[i][j] = t[i][j] + o.t[i][j];
		return ans;
	}
	matrix<base_t, M, N> operator - (const matrix<base_t, M, N>& o)
	{
		matrix<base_t, M, N> ans;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				ans[i][j] = t[i][j] - o.t[i][j];
		return ans;
	}
	template<const int U>
	matrix<base_t, M, U> operator * (const matrix<base_t, N, U>& o)
	{
		matrix<base_t, M, U> ans;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < U; j++)
				for(int k = 0; k < N; k++)
					ans[i][j] += t[i][k] * o.t[k][j];
		return ans;
	}

	matrix<base_t, M, N>& operator += (const matrix<base_t, M, N>& o)
	{
		return *this = *this + o;
	}
	matrix<base_t, M, N>& operator -= (const matrix<base_t, M, N>& o)
	{
		return *this = *this - o;
	}
	template<const int U>
	matrix<base_t, M, U>& operator *= (const matrix<base_t, N, U>& o)
	{
		return *this = *this * o;
	}

	matrix<base_t, M, N> operator + (const base_t& o)
	{
		matrix<base_t, M, N> ans;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				ans[i][j] = t[i][j] + o;
		return ans;
	}
	matrix<base_t, M, N> operator - (const base_t& o)
	{
		matrix<base_t, M, N> ans;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				ans[i][j] = t[i][j] - o;
		return ans;
	}
	matrix<base_t, M, N> operator * (const base_t* o)
	{
		matrix<base_t, M, N> ans;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				ans[i][j] = t[i][j] * o;
		return ans;
	}
	matrix<base_t, M, N> operator / (const base_t& o)
	{
		matrix<base_t, M, N> ans;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				ans[i][j] = t[i][j] / o;
		return ans;
	}

	matrix<base_t, M, N>& operator += (const base_t& o)
	{
		return *this = *this + o;
	}
	matrix<base_t, M, N>& operator -= (const base_t& o)
	{
		return *this = *this - o;
	}
	matrix<base_t, M, N>& operator *= (const base_t& o)
	{
		return *this = *this * o;
	}
	matrix<base_t, M, N>& operator /= (const base_t& o)
	{
		return *this = *this / o;
	}

	matrix<base_t, N, M> tranpose()
	{
		matrix<base_t, N, M> ans;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				ans[j][i] = t[i][j];
		return ans;
	}

	base_t trace()
	{
		base_t sum = base_t(0);
		for(int i = 0; i < min(M, N); i++)
			sum += t[i][i];
		return sum;
	}
};

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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
	matrix<modular<int>, 50, 50> m;
	ll k; cin >> k;

	for(int i = 1; i < 45; i++)
		m[i][i - 1] = 1;

	m[0][9] = 16;
	m[0][19] = 9;
	m[0][29] = 4;
	m[0][39] = 1;

	m = fexp(m, k);

	modular<int> ans = 0;

	for(int i = 0; i < 45; i++)
		ans += m[i][0];

	cout << ans << endl;

	return 0;
}
