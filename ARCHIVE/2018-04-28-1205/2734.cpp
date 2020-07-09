#include <bits/stdc++.h>
using namespace std;

int t, n;
bool dp[MAXN][MAXN][2];
vector<int> p1, p2;

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			p1.push_back (x);
		}
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			p2.push_back (x);
		}
	}

	return 0;
}
