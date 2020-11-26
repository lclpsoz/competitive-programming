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

const int N = 1e6 + 10;

int n;
vector<string> words[N][7];

pair<int, int> cntV (string &s) {
	int q = 0;
	int cLst;
	for (char c : s)
		if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
			++q;
			cLst = c;
		}
	if (cLst == 'a')
		cLst = 0;
	else if (cLst == 'e')
		cLst = 1;
	else if (cLst == 'i')
		cLst = 2;
	else if (cLst == 'o')
		cLst = 3;
	else if (cLst == 'u')
		cLst = 4;
	return {q, cLst};
}

vector<pair<string, string>> frst, sec;

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		auto now = cntV (s);
		words[now.x][now.y].push_back (s);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++)
			while (len (words[i][j]) >= 2) {
				pair<string, string> p;
				p.x = words[i][j].back();
				words[i][j].pop_back ();
				p.y = words[i][j].back();
				words[i][j].pop_back ();
				sec.push_back (p);
			}
			
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++) {
			if (len (words[i][j]))
				for (int k = j+1; k < 5; k++)
					while (len (words[i][j]) and len (words[i][k])) {
						// cout << len (words[i][j]) << ' ' << len (words[i][k]) << '\n';
						frst.push_back ({words[i][j].back(), words[i][k].back()});
						words[i][j].pop_back();
						words[i][k].pop_back();
						break;
					}
		}

	cout << min (len(frst), len(sec)) + (len(sec) - min (len(frst), len(sec)))/2 << '\n';
	while (len (frst) and len (sec)) {
		cout << frst.back().x << ' ' << sec.back().x << '\n';
		cout << frst.back().y << ' ' << sec.back().y << '\n';
		frst.pop_back();
		sec.pop_back();
	}

	while (len (sec) >= 2) {
		auto p1 = sec.back();
		sec.pop_back();
		auto p2 = sec.back();
		sec.pop_back();
		cout << p1.x << ' ' << p2.x << '\n';
		cout << p1.y << ' ' << p2.y << '\n';
	}

	return 0;
}
