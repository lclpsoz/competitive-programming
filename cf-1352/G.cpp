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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

map<int, vector<int>> mp;

void solve(int base, int qnt) {
	if(qnt < 9) {
		vector<int> &vec = mp[qnt];
		for(int i = 0; i < qnt; i++)
			printf("%d%c", vec[i]+base, " \n"[i==qnt-1]);
	} else {
		vector<int> &vec = mp[5];
		for(int i = 0; i < 5; i++)
			printf("%d ", vec[i]+base);
		solve(base+5, qnt-5);
	}
}

int main () {
	mp[4] = {2, 4, 1, 3};
	mp[5] = {1, 3, 5, 2, 4};
	mp[6] = {1, 4, 2, 5, 3, 6};
	mp[7] = {1, 5, 2, 6, 3, 7, 4};
	mp[8] = {1, 5, 2, 6, 3, 7, 4, 8};
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(n < 4)
			printf("-1\n");
		else
			solve(0, n);
	}

	return 0;
}
