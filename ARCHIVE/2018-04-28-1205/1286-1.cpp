#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

typedef pair<int, int> pii;

int n, c, tmp, qnt;
pii arr[MAXN];
vector<pii> dp;
int ans;

int main ()
{
	while (scanf ("%d", &n), n) {
		scanf ("%d", &c);
		for (int i = 0; i < n; i++) {
			scanf ("%d %d", &tmp, &qnt);
			arr[i] = {tmp, qnt};
		}
		int i = 0;
		ans = 0;
		while (i < n) {
			vector<pii> aux;
			for (pii p : dp)
				if (p.second+arr[i].second <= c) {
					ans = max (ans, p.first+arr[i].first);
					aux.push_back ({p.first+arr[i].first, p.second+arr[i].second});
				}
			dp.insert(dp.end(), aux.begin(), aux.end());
			aux.clear();
			dp.push_back (arr[i]);
			ans = max (ans, arr[i].first);
			i++;
		}
		dp.clear ();
		printf ("%d min.\n", ans);
	}

	return 0;
}
