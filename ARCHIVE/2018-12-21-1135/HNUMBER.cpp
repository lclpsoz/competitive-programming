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

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+100;

int t, n, m;
int ans;
vector<int> nums[N];
bool not_prime[N];

void solve (int p, int qnt, int acu) {
	acu = acu*nums[n][p];
	if (qnt&1)
		ans += m/acu;
	else
		ans -= m/acu;
	for (int i = p+1; i < len (nums[n]); i++)
		if (nums[n][i]*1LL*acu <= m)
			solve (i, !qnt, acu);
		else
			return;
}

void sieve () {
	int i = 2;
	for (; i*i < N; i++)
		if (!not_prime[i]) {
			nums[i].push_back (i);
			for (int j = i+i; j < N; j += i) {
				not_prime[j] = true;
				nums[j].push_back (i);
			}
		}
	for (; i < N; i++)
		if (!not_prime[i]) {
			nums[i].push_back (i);
			for (int j = i+i; j < N; j += i) {
				not_prime[j] = true;
				nums[j].push_back (i);
			}
		}
// 	for (int i = 2; i < N; i++) {
// 		int qq = 0;
// 		vector<int> aux;
// 		for (int j = 2; j <= i; j++)
// 			if (!not_prime[j] and i%j == 0) {
// 				++qq;
// 				aux.push_back (j);
// 			}
// 		if (qq != len (nums[i])) {
// 			printf ("%d: %d x %d\n", i, qq, len (nums[i]));
// 			for (int v : nums[i])
// 				printf ("%d ", v);
// 			putchar ('\n');
// 			for (int v : aux)
// 				printf ("%d ", v);
// 			putchar ('\n');
// 		}
// 	}
}

int main () {
	sieve();
	
	scanf ("%d", &t);
	while (t--) {
		ans = 0;
		scanf ("%d %d", &n, &m);
 		assert (n <= 100000 and m <= 100000);
		for (int i = 0; i < len (nums[n]); i++)
			solve (i, 1, 1);
		printf ("%d\n", m-ans);
	}

	return 0;
}
