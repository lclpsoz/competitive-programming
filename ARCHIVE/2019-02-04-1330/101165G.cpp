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

const int N = 4e5+100;

int n;
map<string, int> mp;
int idString = 1;
int parity[N];
int link[N], size[N];

int find (int a) {
	return link[a] == a ? a : link[a] = find (link[a]);
}

bool same (int a, int b) {
	return find (a) == find (b);
}

void unite (int a, int b) {
	a = find (a);
	b = find (b);
	if (size[a] > size[b]) swap (a, b);
	size[b] += size[a];
	parity[b] = parity[a]+parity[b];
	link[a] = b;
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	for (int i = 1; i < N; i++)
		link[i] = i, size[i] = 1, parity[i] = 1;

	cin >> n;
	while (n--) {
		string str1, str2;
		int id1, id2;
		cin >> str1 >> str2;
		if (!mp.count (str1))
			id1 = mp[str1] = idString++;
		id1 = mp[str1];
		
		if (!mp.count (str2))
			mp[str2] = idString++;
		id2 = mp[str2];
		
		if (!same (id1, id2))
			unite (id1, id2);
	}
	
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		printf ("%c\n", parity[find (mp[str])]&1 ? 'N' : 'S');
	}

	return 0;
}
