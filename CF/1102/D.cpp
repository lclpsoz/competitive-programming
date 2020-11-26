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

int n;
string str;
int qnt[5];

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		str[i]-='0';
		qnt[str[i]]++;
	}
	int n3 = n/3;
	for (int i = 0; i < n; i++) {
		if (qnt[0] >= n3) break;
		if (qnt[str[i]] > n3) {
			qnt[str[i]]--;
			qnt[0]++;
			str[i] = 0;
		}
	}
		
	if (qnt[2] > n3)
		for (int i = 0; i < n; i++)
			if (str[i] == 2) {
				qnt[2]--;
				qnt[1]++;
				str[i] = 1;
				if (qnt[2] == n3) break;
			}
				
	for (int i = n-1; i >= 0; i--)
		if (qnt[str[i]] > n3) {
			qnt[str[i]]--;
			if (qnt[2] < n3) {
				qnt[2]++;
				str[i] = 2;
			} else {
				qnt[1]++;
				str[i] = 1;
			}
		}
		
		
	for (int i = 0; i < n; i++)
		putchar (str[i]+'0');
	putchar ('\n');

	return 0;
}
