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

int a[4];
bool adj[10][10];
map<string, int> mp;
int team[10];
int id = 0;
pii ans = {2e9 + 100, - 2e9 - 200};

void eval () {
	vector<int> vec[3];
	for (int i = 0; i < id; i++)
		vec[team[i]].push_back (i);
	int friendShip = 0;
	for (int i = 0; i < 3; i++)
		for (int u : vec[i])
			for (int v : vec[i])
				friendShip += adj[u][v];
	int mini = 2e9+100, maxi = - 2e9 - 100;
	for (int i = 0; i < 3; i++) {
		if (len (vec[i]) == 0) return;
		mini = min (mini, a[i]/len (vec[i]));
		maxi = max (maxi, a[i]/len (vec[i]));
	}
	if (ans.x > (maxi - mini)) {
		ans = {maxi - mini, friendShip};
	} else if (ans.x == (maxi - mini))
		ans.y = max (ans.y, friendShip);
}

void dfs (int now) {
	if (now == id) {
		eval ();
		return;
	}
	for (int i = 0; i < 3; i++) {
		team[now] = i;
		dfs (now+1);
	}
}

int main () {
	int n;
	scanf ("%d", &n);
	while (n--) {
		char arr[3][30];
		scanf ("%s %s %s", arr[0], arr[1], arr[2]);
		int u, v;
		if (mp.count (arr[0]) == 0)
			mp[arr[0]] = id++;
		u = mp[arr[0]];
		if (mp.count (arr[2]) == 0)
			mp[arr[2]] = id++;
		v = mp[arr[2]];
		adj[u][v] = true;
	}
	id = 7;
	scanf ("%d %d %d", &a[0], &a[1], &a[2]);
	dfs (0);
	
	printf ("%d %d\n", ans.x, ans.y);

	return 0;
}
