#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 110;

int t, n, k, r;
int f, s;
int dp[MAXN];
vector<pii> vec;
int ans;

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		dp[0] = 0;
		for (int i = 1; i < MAXN; i++)
			dp[i] = -1;
		while (n--) {
			scanf ("%d %d", &f, &s);
			vec.push_back ({f, s});
		}
		scanf ("%d", &k);
		scanf ("%d", &r);
		ans = 0;
		for (pii p : vec) {
			f = p.first;
			s = p.second;
			for (int i = k; i-s >= 0; i--)
				if (dp[i-s] > -1)
					dp[i] = max (dp[i], dp[i-s]+f);
			/*for (int i = 0; i <= k; i++)
				printf ("%d ", dp[i]);
			putchar ('\n');*/
		}
		vec.clear ();
		for (int i = 0; i < MAXN; i++)
			ans = max (dp[i], ans);
		if (ans >= r)
			printf ("Missao completada com sucesso\n");
		else
			printf ("Falha na missao\n");
	}

	return 0;
}
