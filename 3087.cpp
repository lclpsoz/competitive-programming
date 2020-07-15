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

int mt[105][105];
pii mp[101][10101];

int main () {
	for(int n = 1; n < 100; n+=2) {
		pii st = {n/2, n/2};
		mt[st.x][st.y] = n;
		mp[n][1] = st;
		st.y += 1;
		char mode = 'D';
		for(int s = 2; s <= n*n; s++) {
			// printf("n = %d, s = %d, (%d, %d)\n", n, s, st.x, st.y);
			mt[st.x][st.y] = n;
			mp[n][s] = st;
			switch(mode) {
				case 'D':
					st.x += 1;
					if(mt[st.x][st.y-1] != n)
						mode = 'L';
					break;
				case 'L':
					st.y -= 1;
					if(mt[st.x-1][st.y] != n)
						mode = 'U';
					break;
				case 'U':
					st.x -= 1;
					if(mt[st.x][st.y+1] != n)
						mode = 'R';
					break;
				case 'R':
					st.y += 1;
					if(mt[st.x+1][st.y] != n)
						mode = 'D';
					break;
			}
		}
	}

	int n, s;
	while(scanf("%d %d", &n, &s) != EOF)
		printf("%d %d\n", mp[n][s].x, mp[n][s].y);

	return 0;
}
