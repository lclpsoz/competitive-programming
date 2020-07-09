#include "bits/stdc++.h"
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

const int MOD = 998244353 ;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;

int fact[N];

bool bruteNxt (vector<int> &vec, int k) {
	vec[0]++;
	int p;
	while (vec[p] == k+1) {
		vec[p] = 1;
		if (p == len (vec)-1) return false;
		vec[p+1]++;
		p++;
	}
	return true;
}

bool check (vector<int> vec, vector<int> &ax) {
	for (int i = 0; i < len (vec); i++) if (ax[i] != -1 and vec[i] != ax[i]) return false;
	for (int i = 2; i < len (vec); i++)
		if ((vec[i] != -1 and vec[i-2] != -1 and vec[i] == vec[i-2])) return false;
	return true;
}

int brute (int n, int k, vector<int> ax) {
	vector<int> vec(n, 1);
	int ans = 0;
	vector<string> valids;
	do {
		// for (int i = 0; i < len (vec);i++) printf ("%d ", vec[i]);
		// putchar ('\n');
		ans += check (vec, ax);
		// if (check (vec, ax)) {
		// 	// for (int v : vec) printf ("%d ", v);
		// 	string now = "";
		// 	for (int i = 0; i < len (vec); i+=2) {
		// 		now += (char)(vec[i]+'0');
		// 	}
		// 	valids.push_back (now);
		// // 	putchar ('!');
		// 	// putchar ('\n');
		// 	printf (".\n");
		// }
	} while (bruteNxt (vec, k));
	// sort (valids.begin(), valids.end());
	// for (string s : valids)
	// 	cout << s << '\n';
	return ans;
}

int powMod (int b, int p) {
	int ret = 1;
	while (p) {
		if (p&1)
			ret = (ret * 1LL * b) % MOD;
		p >>= 1;
		b = (b*1LL*b)%MOD;
	}

	return ret;
}

int bin (int a, int b) {
	return (fact[a]*1LL*(powMod ((fact[b]*1LL*fact[a-b])%MOD, MOD-2)))%MOD;
}

int only1 (int k, int sz) {
	return (k*1LL*powMod (k-1, sz-1))%MOD;
}

int between (int k, int sz) {
	int ret = 0;
	for (int i = 0; i <= sz; i++) {
		int now = (bin(sz+1, i) * 1LL * powMod (k, sz-i))%MOD;
		// printf (" i(%d): now = %d\n", i, now);
		ret = ((ll)ret + (now * (i%2 == 0 ? 1 : -1)) + MOD)%MOD;
	}
	return ret;
}

int oneSide (int k, int sz) {
	return powMod (k-1, sz);
}

int solve (int n, int k, vector<int> &vec) {
	// printf ("vec:\n");
	// for (int v : vec) printf ("%d ", v);
	// putchar ('\n');
	vector<int> pos;
	pos.push_back (-1);
	for (int i = 0; i < len (vec); i++)
		if (vec[i] != -1) pos.push_back (i);
	pos.push_back (len(vec));
	// printf ("pos:\n");
	// for (int v : pos) printf ("%d ", v);
	// putchar ('\n');
	if (len (pos) == 2)
		return only1 (k, len (vec));
	else {
		int ret = 1;
		// printf ("here_2\n");
		for (int i = 1; i < len (pos); i++) {
			int sz = pos[i] - pos[i-1] - 1;
			if (pos[i-1] == -1 or i == len(pos)-1)
				ret = (ret * 1LL * oneSide (k, sz))%MOD;
			else
				ret = (ret * 1LL * (between (k, sz) - (vec[pos[i]] == vec[pos[i-1]])))%MOD;
			// printf ("pos[%d] = %d, pos[%d] =  %d\n", i, pos[i], i-1, -pos[i-1]);
			// printf ("%d: sz = %d, ret = %d\n", i, sz, ret);
		}
		return ret;
	}
}

int main () {
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = (i*1LL*fact[i-1])%MOD;
	// for (int i = 1; i <= 5; i++)
	// 	for (int j = 0; j <= i; j++)
	// 		printf ("%d%c", bin (i, j), " \n"[j==i]);

	int n, k;
	scanf ("%d %d", &n, &k);
	vector<int> vec(n, 0), evens, odds, q(n, 0), ax(n, -1);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec[i] = x;
		if (i%2 == 0) evens.push_back (x);
		else odds.push_back (x);
		// printf ("%d: %d vs %d\n", i, len (evens), len (odds));
	}
	int brt = brute (n, k, vec);
	// if (!check (vec, ax)) {
	// 	printf ("0\n");
	// 	exit (0);
	// }
	// fill (ax.begin(), ax.end(), 0);

	// printf ("%d vs %d\n", len (evens), len (odds));
	// int ans = solve (n, k, evens);
	// ans = (ans * 1LL * solve (n, k, odds))%MOD;
	// printf ("OUT!!\n");
	// printf ("bet = %d\n", between (k, 3)); // REMEMBER TO -1 IF THE EXTREMES ARE EQUAL!!

	// printf ("ans = %d\n", ans);
	// printf ("brute = %d\n", brt);
	printf ("%d\n", brt);

	return 0;
}
