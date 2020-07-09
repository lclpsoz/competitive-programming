// Probably possible with Dijkstra
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1e6+10;

int n, hp;
int d, m;
int sum;
int minis[MAXN];

// Stores the minimum amount
// of mana for each damage possible.
int knap (vector<pii> spells)
{
	int ans = 1e9;
	minis[0] = 0;
	for (pii p : spells) {
		int mana = p.first;
		int k = p.second;
		for (int i = sum; i >= 0; i--) {
			if (minis[i] < 1e9) {
				// printf ("%d %d\n", k, i);
				minis[i+k] = min (minis[i+k], minis[i]+mana);
				if (i+k >= hp)
					ans = min (ans, minis[i+k]);
			}
		}
	}

	return ans == 1e9 ? -1 : ans;
}

int main ()
{
	while (~scanf ("%d %d", &n, &hp)) {
		vector<pii> spells;
		sum = 0;
		while (n--) {
			scanf ("%d %d", &d, &m);
			spells.push_back ({m, d});
			sum += d;
		}
		for (int i = 0; i <= sum; i++) minis[i] = 1e9;

		printf ("%d\n", knap (spells));

		spells.clear();
	}

	return 0;
}
