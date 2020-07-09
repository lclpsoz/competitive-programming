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
string a, b;
map<string, int> mp;

int main () {
    cin >> n;
    while (n--) {
        cin >> a >> b;
        mp[b]++;
    }
    cout << mp["X"] << " Hobbit(s)\n";
    cout << mp["H"] << " Humano(s)\n";
    cout << mp["E"] << " Elfo(s)\n";
    cout << mp["A"] << " Anao(s)\n";
    cout << mp["M"] << " Mago(s)\n";

	return 0;
}
