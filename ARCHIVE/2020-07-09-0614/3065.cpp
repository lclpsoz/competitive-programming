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

int teste = 0;

int main () {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	while(cin >> n, n) {
		cin >> str;
		vector<int> pos;
		for(int i = 0; i < len(str); i++)
			if(str[i] == '+' or str[i] == '-')
				pos.push_back(i);
		int ans = 0;
		if(len(pos) == 0)
			ans += stoi(str);
		else
			ans += stoi(str.substr(0, pos[0]));
		for(int i = 0; i < len(pos)-1; i++) {
			int v = stoi(str.substr(pos[i]+1, pos[i+1]-pos[i]-1));
			if(str[pos[i]] == '-')
				v *= -1;
			ans += v;
		}
		if(len(pos)) {
			int v = stoi(str.substr(pos.back()+1, len(str) - pos.back() - 1));
			if(str[pos.back()] == '-') v *= -1;
			ans += v;
		}
		cout << "Teste " << ++teste << '\n';
		cout << ans << "\n\n";
	}

	return 0;
}
