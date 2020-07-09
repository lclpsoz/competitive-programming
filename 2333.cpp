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
vector<int> vec;

int main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	for(int i = 0; i < n; i++)
		vec.push_back(vec[i]);
	int pos = 0;
	int sum = 0;
	int ans = 0;
	for(int i = 0; i < 2*n-1; i++) {
		if(vec[i] > vec[i] + sum) {
			pos = i;
			sum = vec[i];
		} else {
			if(i-pos == n)
				do {
					sum -= vec[pos++];
				} while(vec[pos] <= 0);
			sum += vec[i];
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);

	return 0;
}
