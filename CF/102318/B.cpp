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

map<char, set<char>> mp;

int main () {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for(int i = 0; i < 9; i++) {
		mp[i].insert(i);
		mp[i].insert(i+9);
		if(i > 0) {
			mp[i].insert(i-1);
			mp[i].insert(i+8);
		}
		if(i < 8) {
			mp[i].insert(i+1);
			mp[i].insert(i+10);
		}
	}
	for(int i = 9; i < 18; i++) {
		mp[i].insert(i);
		mp[i].insert(i-9);
		if(i > 9) {
			mp[i].insert(i-1);
			mp[i].insert(i+8);
			mp[i].insert(i-10);
		}
		if(i < 17) {
			mp[i].insert(i+9);
			mp[i].insert(i-8);
			mp[i].insert(i+1);
			if(i < 16)
				mp[i].insert(i+10);
		}
	}
	for(int i = 18; i < 26; i++) {
		mp[i].insert(i);
		mp[i].insert(i-9);
		mp[i].insert(i-8);
		if(i > 18) {
			mp[i].insert(i-1);
			mp[i].insert(i-10);
		}
		if(i < 25) {
			mp[i].insert(i+1);
		}
	}

	// for(int i = 0; i < 26; i++) {
	// 	printf("%d: ", i);
	// 	for(int v : mp[i])
	// 		printf(" %c", v+'a');
	// 	putchar('\n');
	// }

	int n;
	cin >> n;
	string a, b;
	while(n--) {
		cin >> a >> b;
		if(a == b) {
			cout << "1\n";
		}
		else if(len(a) == len(b)) {
			bool ans = true;
			for(int i = 0; i < len(a); i++) {
				if(mp[a[i]-'a'].count(b[i]-'a')) {
					assert(mp[b[i]-'a'].count(a[i]-'a') == 1);
				}
				else {
					assert(mp[b[i]-'a'].count(a[i]-'a') == 0);
					ans = false;
				}
			}
			if(ans)
				cout << "2\n";
			else
				cout << "3\n";
		} else {
			cout << "3\n";
		}
	}

	return 0;
}
