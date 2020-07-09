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

string s;
int qnt[30];
vector<string> vec, sVec;
vector<int> idx;
set<string> ans;

void prt () {
	string now = "";
	for (int i = 0; i < len (idx); i++) {
		now += vec[idx[i]];
		if (i < len (idx)-1) now += ' ';
	}
	ans.insert (now);
}

int ok () {
	int ret = 1;
	for (int i = 0; i < 30; i++)
		if (qnt[i] < 0) return -1;
		else if (qnt[i] > 0) ret = 0;
	return ret;
}

void solve (int p = 0) {
	if (p == len (vec)) return;
	
	string &now = vec[p];
	for (int i = 0; i < len (now); i++)
		if (now[i] != ' ')
			qnt[now[i]-'A']--;
	idx.push_back (p);
	int val = ok ();
	if (val == 0)
		solve (p+1);
	else if (val == 1)
		prt ();
	
	idx.pop_back ();
	for (int i = 0; i < len (now); i++)
		if (now[i] != ' ')
			qnt[now[i]-'A']++;
	solve (p+1);
}

int main () {
	cin.tie (NULL);
	ios::sync_with_stdio (false);
	
	while (cin >> s, s != "#") {
		vec.push_back (s);
// 		cout << s << '\n';
	}

	cin.ignore ();
	while (getline (cin, s), s != "#") {
		sVec.clear();
//  		cout << "s: " << s << '\n';
		for (int i = 0; i < len (s); i++)
			if (s[i] != ' ')
				qnt[s[i]-'A']++;
		for (int pos = 0, i = 1; s[i-1] != '\0'; i++) {
			if (pos < i and (s[i] == ' ' or s[i] == '\0')) {
				sVec.push_back (s.substr (pos, i-pos));
				pos = i+1;
			}
		}
		sort (sVec.begin(), sVec.end());
		solve ();
		
// 		cout << "ax: " << ax << '\n';
// 		cout << len (ans) << '\n';
		for (string ss : ans) {
			vector<string> now;
			for (int pos = 0, i = 1; ss[i-1] != '\0'; i++) {
				if (pos < i and (ss[i] == ' ' or ss[i] == '\0')) {
					now.push_back (ss.substr (pos, i-pos));
					pos = i+1;
				}
			}
			sort (now.begin(), now.end());
			if (len (now) == len (sVec)) {
				bool test = true;
				for (int i = 0; i < len (now); i++)
					if (now[i] != sVec[i]) {
						test = false;
						break;
					}
				if (test)
					continue;
			}
			
			cout << s << " = " << ss << '\n';
		}
			
		ans.clear();
		memset (qnt, 0, sizeof qnt);
	}

	return 0;
}
