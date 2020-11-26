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

const int N = 1e6+10;

int t, k;
char s[N], a[N], b[N];
set<int> alfa[30];
bool used[30];
char arr[30];

bool solve (int p) {
	if (p == k) {
		printf ("YES\n%s\n", arr);
		return true;
	}
	for (int v : alfa[p]) {
		if (used[v]) continue;
		used[v] = true;
		arr[p] = (char)(v+'a');
		if (solve (p+1))
			return true;
		used[v] = false;
		arr[p] = '\0';
	}
	
	return false;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %s %s %s", &k, s, a, b);
		for (int i = 0; i < k; i++) {
			alfa[i].clear();
			for (int j = 0; j < k; j++)
				alfa[i].insert (j);
		}
		
		bool ans = true;
		for (int i = 0; s[i] != '\0'; i++) {
			int now = s[i]-'a';
			int l = a[i]-'a';
			int r = b[i]-'a';
			for (int j = 0; j < k; j++)
				if (j < l or j > r)
					alfa[now].erase (j);
			if (alfa[now].empty()) {
				ans = false;
				break;
			}
		}
		if (!ans)
			printf ("NO\n");
		else
			if (!solve (0))
				printf ("NO\n");
	}

	return 0;
}
