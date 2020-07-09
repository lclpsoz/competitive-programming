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

const int N = 5010;

int n, q;
int a[N];
pii arr[5010];
int pref1[N], pref2[N];
bool notZero[N];
// int t[4*N];

// void build(int v, int tl, int tr) {
//     if (tl == tr) {
// 		qnt[v].x = a[tl] == 1;
// 		qnt[v].y = a[tl] == 2;
//     } else {
//         int tm = (tl + tr) / 2;
//         build(v*2, tl, tm);
//         build(v*2+1, tm+1, tr);
// 		qnt[v] = {qnt[v*2].x + qnt[v*2+1].x, qnt[v*2].y + qnt[v*2+1].y};
//     }
// }
// 
// pii sum (int v, int tl, int tr, int l, int r)
// {
// 	if (l > r)
// 		return {0, 0};
// 	if (l == tl && r == tr)
// 		return {qnt[v].x, qnt[v].y};
// 	int tm = (tl + tr) / 2;
// 
// 	pii ret = {0, 0};
// 	pii now = sum (v*2, tl, tm, l, min(r, tm));
// 	ret.x += now.x, ret.y += now.y;
// 	now = sum (v*2 + 1, tm+1, tr, max (l, tm+1), r);
// 	ret.x += now.x, ret.y += now.y;
// 	
// 	return ret;
// }



int main () {
	scanf ("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf ("%d %d", &arr[i].x, &arr[i].y);
		for (int j = arr[i].x; j <= arr[i].y; j++) {
			notZero[j] = true;
			a[j]++;
		}
	}
	
	int ans = 0;
	int base = 0;
	for (int i = 1; i <= n; i++) {
		base += notZero[i];
		pref1[i] = (a[i] == 1) + pref1[i-1];
		pref2[i] = (a[i] == 2) + pref2[i-1];
	}
	for (int i = 0; i < q; i++)
		for (int j = i+1; j < q; j++) {
			int now = base;
			pii inter = {max (arr[i].x, arr[j].x), min (arr[i].y, arr[j].y)};
			if (inter.x <= inter.y)
				now -= pref2[inter.y] - pref2[inter.x-1];
			now -= pref1[arr[i].y] - pref1[arr[i].x-1];
			now -= pref1[arr[j].y] - pref1[arr[j].x-1];
//  			printf ("%d\n", now);
			ans = max (now, ans);
		}
	printf ("%d\n", ans);

	return 0;
}
