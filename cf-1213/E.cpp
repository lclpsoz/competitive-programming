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
string s, t;
string ans = "---";

bool check(string txt, string now) {
	for (int i = 0; i < len(txt); i++)
		if(txt[i] == now[0] and txt[(i+1)%len(txt)] == now[1])
			return true;
	return false;
}
bool check2(string txt, string now) {
	for (int i = 0; i < len(txt)-1; i++)
		if(txt[i] == now[0] and txt[(i+1)%len(txt)] == now[1])
			return true;
	return false;
}

int main () {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> s >> t;
	cout << "YES\n";
	if(s[0] == s[1] or t[0] == t[1]) {
		string txt = "abc";
		if(check("abc", s) or check("abc", t)) txt = "cba";
		for(int i = 0; i < n; i++) cout << txt;
	}
	else if(s[0] == t[0]) {
		for(char c = 'a'; c <= 'c'; c++)
			if(c != s[0])
				for(int i = 0; i < n; i++) cout << c;
		for(int i = 0; i < n; i++) cout << s[0];
	}
	else if(s[1] == t[1]) {
		for(int i = 0; i < n; i++) cout << s[1];
		for(char c = 'a'; c <= 'c'; c++)
			if(c != s[1])
				for(int i = 0; i < n; i++) cout << c;
	} 
	else {
		string txt = "abc";
		do {
			if(!check2(txt, s) and !check2(txt, t)) break;
		} while(next_permutation(txt.begin(), txt.end()));
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n; j++) cout << txt[i];
	}

	cout << '\n';


	return 0;
}
