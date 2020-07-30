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

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(x%m);
}

////////////////////////// Solution starts below. //////////////////////////////



int mdc(int a, int b) {
	if(b==0) return a;
	return mdc(b, a%b);
}

int mmc(int a, int b) {
	return (a*b)/mdc(a,b);
}

vector<int> cross(vector<int> &v1, vector<int> &v2, int m) {
	assert(len(v1) == len(v2));
	vector<int> ax(len(v1), 0);
	for(int i = 0; i < len(v1); i++)
		for(int j = 0; j < len(v2); j++) {
			if(v1[i] and v2[j]) {
				// printf("|| %d %d\n", v1[i], v2[j]);
				// printf("||| %d %d\n", i, j);
				int val = (i+j)%m;
				ax[val] = mod(ax[val] + v1[i]*1LL*v2[j]);
			}
		}

	return ax;
}

int main () {
	int n, b, k, m;
	for(int tt = 1; tt <= 1; tt++) {
		vector<int> digits;
		int qnt[15];
		scanf("%d %d %d %d", &n, &b, &k, &m);
		// if(tt == 44) {
		// 	printf("%d %d %d %d\n", n, b, k, m);	
		// }
		memset(qnt, 0, sizeof qnt);
		for(int i = 0; i < n; i++) {
			int val;
			scanf("%d", &val);
			// if(tt == 44)
			// 	printf("%d ", val);
			qnt[val]++;
		}
		// putchar('\n');
		for(int i = 1; i <= 9; i++)
			if(qnt[i])
				digits.push_back(i%m);

		map<vector<int>, int> mp;
		vector<int> vec = digits;
		int qNow = 0;
		mp[vec] = 1;
		for(int i = 2;; i++) {
			// printf("%2d: ", i);
			for(int j = 0; j < len(vec); j++) {
				vec[j] = (vec[j]*10)%m;
				// printf("%d ", vec[j]);
			}
			// putchar('\n');

			if(mp.count(vec)) {
				qNow = i;
				break;
			} else
				mp[vec] = i;
		}
		int stCycle = mp[vec];
		int sizeCycle = qNow-mp[vec];
		// printf("%3d: %d -> %d [%d]\n", m, mp[vec], qNow-1, sizeCycle);

		vector<int> ans(105, 0);
		vec.clear();
		for(int i = 1; i <= 9; i++)
			for(int j = 0; j < qnt[i]; j++)
				vec.push_back(i%m);
		for(int v : vec)
			ans[v] += 1;
		int lstPos = 1;

		// Before Cycles
		if(stCycle > 1) {
			for(int i = lstPos+1; i < min(b, stCycle); i++) {
				// printf("vec in %2d: ", i);
				for(int j = 0; j < len(vec); j++) {
					vec[j] = (vec[j]*10)%m;
					// printf("%d ", vec[j]);
				}
				// putchar('\n');
				vector<int> ansNow(105, 0);
				for(int v : vec)
					ansNow[v] += 1;
				vector<int> ax = cross(ans, ansNow, m);
				// printf("AX in %d:\n", i);
				// for(int j = 0; j < m; j++)
				// 	printf("%d: %d\n", j, ax[j]);
				ans = ax;
				lstPos = i;
			}
		}

		// In Cycles
		// Needs vec updated
		vector<vector<int>> allCycles(64);
		if(b >= stCycle+sizeCycle) {
			// printf("IN CYCLES!!!!!\n");
			vector<int> ansCycle(105, 0);
			// printf("vec in st-1: ");
			vector<int> vec2 = vec;
			// vec.clear();
			// for(int i = 1; i <= 9; i++)
			// 	for(int j = 0; j < qnt[i]; j++)
			// 		vec.push_back(i%m);
			for(int j = 0; j < len(vec); j++) {
				vec[j] = (vec[j]*10)%m;
				// vec2[j] = (vec2[j]*10)%m;
				// printf("%d ", vec[j]);
			}
			for(int v : vec)
				ansCycle[v] += 1;
			// lstPos+2 because I have to count this above as a cycle

			// TODO: THIS IS WRONG!!!
			// The correct way is to get the cycle amounts separe,
			// NOT to change vec to it starting state.
			// lstPos++;
			for(int i = 1; i < sizeCycle; i++) {
				// printf("vec in %2d: ", i);
				for(int j = 0; j < len(vec); j++) {
					vec[j] = (vec[j]*10)%m;
					// vec2[j] = (vec2[j]*10)%m;
					// printf("%d ", vec[j]);
				}
				// putchar('\n');
				vector<int> ansNow(105, 0);
				// vector<int> ansNowVec2(105, 0);
				for(int v : vec)
					ansNow[v] += 1;
				// for(int v : vec2)
				// 	ansNowVec2[v] += 1;
				vector<int> ax = cross(ansCycle, ansNow, m);
				// printf("ansCycle in %d:\n", i);
				// for(int j = 0; j < m; j++)
				// 	printf("%d: %d\n", j, ax[j]);
				ansCycle = ax;
				// lstPos++;
			}
			// vector<int> ax = cross(ans, ansCycle, m);
			// // printf("AX after ansCycle BASIC, lstPos = %d\n", lstPos);
			// // for(int j = 0; j < m; j++)
			// // 	printf("%d: %d\n", j, ax[j]);
			// // printf("-----------\n");
			// ans = ax;
			vec = vec2;

			allCycles[0] = ansCycle;
			for(int i = 1; i < 64; i++) {
				vector<int> ax = cross(allCycles[i-1], allCycles[i-1], m);
				// printf("DOUBLE!!! after ansCycle INTERN\n");
				// for(int j = 0; j < m; j++)
				// 	printf("%d: %d\n", j, ax[j]);
				// printf("-----------\n");
				allCycles[i] = ax;
			}
			ll pp2 = 65536*1LL*65536;
			// ll pp2 = 1;
			// printf("\nANS:\n");
			// for(int j = 0; j < m; j++)
			// 	printf("%d: %d\n", j, ans[j]);
			for(int b2 = 32; b2 >= 0;b2--) {
				for(;lstPos+pp2*sizeCycle < b;) {
					vector<int> ax2 = cross(ans, allCycles[b2], m);
					lstPos += pp2*sizeCycle;
					// printf("b2 = %d, pp2 = %lld, sizeCycle = %d\n", b2, pp2, sizeCycle);
					// printf("AX after ansCycle INTERN lstPos = %d\n", lstPos);
					// for(int j = 0; j < m; j++)
					// 	printf("%d: %d\n", j, allCycles[b2][j]);
					// printf("-----------\n");
					ans = ax2;
				}
				pp2/=2;
			}
		}

		// After cycle
		// Needs vec updated
		// Needs lstPos updated
		if(lstPos < b) {
			// printf("AFTER CYCLES!!!!!\n");
			for(int i = lstPos+1; i <= b; i++) {
				// printf("vec in %2d: ", i);
				for(int j = 0; j < len(vec); j++) {
					vec[j] = (vec[j]*10)%m;
					// printf("%d ", vec[j]);
				}
				// putchar('\n');
				vector<int> ansNow(105, 0);
				for(int v : vec)
					ansNow[v] += 1;
				vector<int> ax = cross(ans, ansNow, m);
				// printf("AX in %d:\n", i);
				// for(int j = 0; j < m; j++)
				// 	printf("%d: %d\n", j, ax[j]);
				ans = ax;
				lstPos = i;
			}
		}
		// printf("\nANS:\n");
		// for(int j = 0; j < m; j++)
		// 	printf("%d: %d\n", j, ans[j]);
		printf("%d\n", ans[k]);
	}


	return 0;
}
