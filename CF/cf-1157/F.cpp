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

const int N = 2e5 + 10;

int a[N];
int l_bst, r_bst;
map<int, int> mp, ans;
int maxAns = -1;
int valMin, valMax;

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	sort (a, a+n);
	int now = 0;
	while (now < n) {
		mp.clear();
		int rig = now;
		for (int i = now+1; i < n; i++)
			if (abs (a[i] - a[i-1]) > 1)
				break;
			else
				rig = i;
		for (int i = now; i <= rig; i++)
			mp[a[i]]++;
//  		printf ("now = %d rig = %d\n", now, rig);
		
		int maxVal = a[now];
		int qnt = mp[a[now]];
		for (int i = a[now] + 1; mp[i] >= 2; i++) {
			maxVal = i;
			qnt += mp[i];
		}
		if (mp[maxVal+1] > 0) {
			qnt++;
			maxVal++;
		}
//  		printf ("minVal: %d maxVal: %d\n", a[now], maxVal);
// 			printf ("aHERE\n");
		if (qnt > maxAns) {
			valMin = a[now];
			valMax = maxVal;
			maxAns = qnt;
			ans.clear();
// 			printf ("HERE\n");
			for (int i = now; a[i] <= maxVal and i <= rig; i++) {
// 				printf ("i: %d | %d\n", i, a[i]);
				ans[a[i]]++;
			}
// 			printf ("OUT\n");
// 			printf ("5: %d\n", ans[5]);
		}
		now = rig + 1;
	}
	printf ("%d\n", maxAns);
	for (int i = valMin; i <= valMax; i++) {
// 		printf ("%d: %d\n", i, ans[i]);
		printf ("%d ", i);
		ans[i]--;
	}
	for (int i = valMax; i >= valMin; i--) {
		for (int j = 0; j < ans[i]; j++)
			printf ("%d ", i);
	}
	putchar ('\n');
	
	
	return 0;
}
