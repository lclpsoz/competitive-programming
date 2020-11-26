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

const int INF = 2e9;
const int A = 30;

int n;
string str;
int chQnt[2][A];
vector<int> ch;
vector<int> qnt;

int main () {
	ios::sync_with_stdio (false); cin.tie (0);
	cin >> n;
	int now = 0, bef = 1;
	cin >> str;
	int ans = 0;
	ch.clear(), qnt.clear();
	for (int i = 0; i < len (str); i++) {
		str[i] -= 'a';
		if (ch.empty() or ch.back() != str[i]) {
			ch.push_back (str[i]);
			qnt.push_back (0);
		}
		qnt.back()++;
	}
	for (int i = 0; i < len(ch); i++) {
		chQnt[now][ch[i]] = max (chQnt[now][ch[i]], qnt[i]);
		// printf ("||%c: %d\n", ch[i]+'a', qnt[i]);
	}
	--n;
	now = !now, bef = !bef;
	// for (int i = 0; i < 3; i++)
	// 	printf ("||%c: %d\n", i+'a', chQnt[bef][i]);
	while (n--) {
		for (int i = 0; i < A; i++) chQnt[now][i] = 0;
		cin >> str;
		ch.clear(), qnt.clear();
		for (int i = 0; i < len (str); i++) {
			str[i] -= 'a';
			if (ch.empty() or ch.back() != str[i]) {
				ch.push_back (str[i]);
				qnt.push_back (0);
			}
			qnt.back()++;
		}

		if (len (ch) == 1) {
			chQnt[now][ch.back()] = (int)min ((ll)INF, chQnt[bef][ch.back()]*1LL*(qnt.back()+1) + qnt.back());
			for (int i = 0; i < A; i++)
				if (i != ch.back () and chQnt[bef][i])
					chQnt[now][i] = 1;
		} else {
			if (*ch.begin() == ch.back()) {
				if (chQnt[bef][ch.back()])
					chQnt[now][ch.back()] = qnt.back() + *qnt.begin() + 1;
			} else {
				if (chQnt[bef][*ch.begin()])
					chQnt[now][*ch.begin()] = *qnt.begin() + 1;
				if (chQnt[bef][ch.back()])
					chQnt[now][ch.back()] = qnt.back() + 1;
			}
			for (int i = 0; i < len (ch); i++)
				chQnt[now][ch[i]] = max (chQnt[now][ch[i]], qnt[i]);
			for (int i = 0; i < A; i++)
				chQnt[now][i] = max (chQnt[now][i], (int)(chQnt[bef][i] >= 1));
		}
		// putchar ('\n');

		// for (int i = 0; i < 3; i++) printf ("%c: %d\n", 'a'+i, chQnt[now][i]);

		now = !now, bef = !bef;
	}
	for (int i = 0; i < A; i++)
		ans = max (ans, chQnt[bef][i]);
	printf ("%d\n", ans);

	return 0;
}
