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

const int S = 1e5;

int n, d, c;
ll ans = 0;
char str[S], ansName[S];

int main () {
	scanf ("%d %d %d", &n, &d, &c);
	while (n--) {
		scanf ("%s", str);
		ll now = 0;
		vector<int> vec;
		for (int i = 0; i < d; i++) {
			int x;
			scanf ("%d", &x);
			vec.push_back (x);
		}
		bool state = 0; // maxi
		int maxi = -1, mini = -1;
		vector<pair<ll, int>> last;
		for (int i = d-1; i >= 0; i--) {
			// printf (" i = %d, maxi = %d, mini = %d, now = %lld\n", i, maxi, mini, now);
			if (state == 0) {
				if (vec[i] > maxi)
					maxi = vec[i];
				else if (vec[i] < maxi) {
					mini = vec[i];
					state = 1;
				}
			} else {
				if (vec[i] < mini)
					mini = vec[i];
				else if (vec[i] > mini) {
					ll val = (maxi - mini)*500 - 2*c;
					while (!last.empty() and ((last.back().y-mini)*500 - 2*c) >= val + last.back().x) {
						now -= last.back().x;
						maxi = last.back().y;
						last.pop_back ();
					}
					now += max (0, (maxi - mini)*500 - 2*c);
					last.push_back ({max (0, (maxi - mini)*500 - 2*c), maxi});
					maxi = vec[i];
					state = 0;
				}
			}
		}
		if (state == 1) {
			ll val = (maxi - mini)*500 - 2*c;					
			// if (len (last))
			// 		printf ("  i = %d, %d %lld\n", -1, ((last.back().y-mini)*500 - 2*c), val + last.back().x);

			while (!last.empty() and ((last.back().y-mini)*500 - 2*c) >= val + last.back().x) {
				now -= last.back().x;
				maxi = last.back().y;
				last.pop_back ();
			}
			now += max (0, (maxi - mini)*500 - 2*c);
			last.push_back ({max (0, (maxi - mini)*500 - 2*c), maxi});
		}
		if (now > ans) {
			for (int i = 0; str[i] != '\0'; i++) ansName[i] = str[i], ansName[i+1] = '\0';
			ans = now;
		}
	}
	if (ans == 0)
		printf ("None 0\n");
	else
		printf ("%s %lld\n", ansName, ans);


	return 0;
}
