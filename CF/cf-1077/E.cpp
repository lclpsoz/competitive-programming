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

const int N = 2e5+10;

int n;
vector<int> vec;
int arrQnt[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back (x);
	}
	sort (vec.begin(), vec.end());
	int id = 1;
	arrQnt[id]++;
	for (int i = 1; i < len (vec); i++)
		if (vec[i] == vec[i-1])
			arrQnt[id]++;
		else
			arrQnt[++id]++;
	
	vector<int> qnt;
	for (int i = 1; i <= id; i++)
		qnt.push_back (arrQnt[i]);
	sort (qnt.begin(), qnt.end());
	
	int ans = 0;
	for (int i = 1; ; i++) {
		int ax = i, acu = 0;
// 		printf ("i: %d\n", i);
		for (int j = 0; j < len (qnt);) {
			if (qnt[j] >= ax) {
// 				printf (" q: %d\n", qnt[j]);
				acu += ax;
				ax *= 2;
			}
			auto it = lower_bound (qnt.begin()+j+1, qnt.end(), ax);
			if (it == qnt.end()) break;
			else
				j = (int)(it-qnt.begin());
		}
		if (acu == 0)
			break;
		ans = max (ans, acu);
	}
	printf ("%d\n", ans);
	
	return 0;
}
