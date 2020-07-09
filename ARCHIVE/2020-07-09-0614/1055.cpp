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

int t, n;
deque<int> deq;

int main () {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			deq.push_back(x);
		}
		sort(deq.begin(), deq.end());
		vector<int> vec;
		deque<int> deq2 = deq;
		while(!deq.empty()) {
			if(len(deq)%2) {
				vec.push_back(deq.front());
				deq.pop_front();
			} else {
				vec.push_back(deq.back());
				deq.pop_back();
			}
		}
		ll ans1, ans2;
		ans1 = ans2 = 0;
		for(int i = 1; i < len(vec); i++)
			ans1 += abs(vec[i]-vec[i-1]), printf("|%d\n", vec[i]);
		vec.clear();
		while(!deq2.empty()) {
			if(len(deq2)%2) {
				vec.push_back(deq2.back());
				deq2.pop_back();
			} else {
				vec.push_back(deq2.front());
				deq2.pop_front();
			}
		}
		printf("-\n");
		for(int i = 1; i < len(vec); i++)
			ans2 += abs(vec[i]-vec[i-1]), printf("|%d\n", vec[i]);
		printf("%lld\n", max(ans1, ans2));
	}


	return 0;
}
