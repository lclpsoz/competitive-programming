#include "bitset"
#include "string"
#include "iostream"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+100, N2 = 4e5+100;

int n, m;
string str1, str2;
bitset<N2> p, t;
ll vals[N];

void solve (char x, char y, ll val) {
	for (int i = 0; i < n; i++)
		p[i] = p[i+n] = (str1[i] == x);
	for (int i = 0; i < m; i++)
		t[i] = (str2[i] == y);
	for (int i = 0; i < n; i++) {
		vals[i] += val*(t&p).count();
		t <<= 1;
	}
	t.reset();
}

int mdc (int a, int b) {
	if (a == 0) return b;
	return mdc (b%a, a);
}

int main () {
	cin.tie (0); cout.tie (0);
	ios::sync_with_stdio (false);
	int a, b, c, h, ans = 0;
	cin >> a >> b >> c >> h;
	cin >> str1 >> str2;
	
	n = str1.size();
	m = str2.size();
	// n >= m
	
	solve ('R', 'A', a);
	solve ('N', 'B', b);
	solve ('E', 'C', c);
	
	for (int i = 0; i < n; i++)
		if (vals[i] >= h)
			++ans;

	int md = mdc (n, ans);
	n /= md, ans /= md;
	cout << ans << ' ' << n << '\n';
	

	return 0;
}
