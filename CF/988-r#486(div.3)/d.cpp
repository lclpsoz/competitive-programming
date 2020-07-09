#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 2e5+10;

int n;

int f (int v) {
	return __builtin_popcount (abs (v));
}

int main ()
{
	int x;
	scanf ("%d", &n);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		vec.pb (x);
	}
	sort (vec.begin(), vec.end());
	int ans[3] = {0, 0, 0};
	x = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; vec[i]+j <= 1e9; j <<= 1) {
			auto it = lower_bound (vec.begin()+i, vec.end(), vec[i]+j);
			if (it != vec.end() && *it == vec[i]+j) {
				if (x == 0) {
					ans[0] = i;
					// printf ("%d\n", i);
					ans[1] = it-vec.begin();
					x = 1;
				}
				auto it2 = lower_bound (it+1, vec.end(), *it+j);
				// printf (" k: %d\n", k);
				if (it2 != vec.end() && *it2 == *it+j) {
					// printf ("%d\n", i);
					ans[0] = i;
					ans[1] = it-vec.begin();
					ans[2] = it2-vec.begin();
					x = 2;
					break;
				}
			}
		}
		if (x == 2) break;
	}

	printf ("%d\n", x+1);
	for (int i = 0; i <= x; i++)
		printf ("%d ", vec[ans[i]]);
	putchar ('\n');

	return 0;
}
