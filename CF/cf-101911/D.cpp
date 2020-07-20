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

const int N = 1e7 + 10;

int n;
int qnt[N];
vector<int> inp;
vector<pii> aux[N];

int main () {
	scanf("%d", &n);
	vector<pii> vec;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		inp.push_back(x);
		qnt[x]++;
	}
	for(int i = 1; i < N; i++)
		if(qnt[i])
			vec.push_back({i, qnt[i]});
	vector<pii> ans;
	for(pii p : vec) {
		int val = p.x;
		int amnt = p.y;
		for(int i = 1; amnt and i*i <= val; i++)
			if(val%i == 0)
				if(amnt > 1 and i != val/i) {
					amnt -= 2;
					aux[val].push_back({i, val/i});
					aux[val].push_back({val/i, i});
				} else {
					amnt -= 1;
					aux[val].push_back({i, val/i});
				}
		if(amnt) {
			printf("NO\n");
			exit(0);
		}
	}
	printf("YES\n");
	for(int i = 0; i < n; i++) {
		int val = inp[i];
		printf("%d %d\n", aux[val].back().x, aux[val].back().y);
		aux[val].pop_back();
	}

	return 0;
}
