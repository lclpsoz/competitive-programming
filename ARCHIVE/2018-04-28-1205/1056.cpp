#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pic;
typedef pair<int, pic> piic;
const int MAXN = 110;

int t, n, m, total;
map<int, int> divs;
int qnt_divs[MAXN];
map<int, int> multi;
int qnt_multi[MAXN];
bool adj[MAXN][MAXN];

void rem_vert (int x, char c)
{
	if (c == 'D') {
		qnt_divs[x] = 0;
		for (int i = 1; i <= m; i++)
			if (adj[x][i]) {
				total--;
				adj[x][i] = false;
				qnt_multi[i]--;
			}
	}
	else {
		qnt_multi[x] = 0;
		for (int i = 1; i <= n; i++)
			if (adj[i][x]) {
				total--;
				adj[i][x] = false;
				qnt_divs[i]--;
			}
	}
}

int rem_edges ()
{
	priority_queue<piic> pq;
	int ret = 0;

	for (pair<int, int> pa : divs)
		pq.push ({qnt_divs[pa.first], {pa.first, 'D'}});
	for (pair<int, int> pa : multi)
		pq.push ({qnt_multi[pa.first], {pa.first, 'M'}});
	while (!pq.empty() && total) {
		piic x = pq.top();
		// printf("TRY: %d %d %c %d\n", x.first, x.second.first, x.second.second, total);
		pq.pop();
		if (x.second.second == 'D' && x.first != qnt_divs[x.second.first]) {
			// printf ("    NEW: %d\n", qnt_divs[x.second.first]);
			pq.push ({qnt_divs[x.second.first], x.second});
			continue;
		}
		else if (x.second.second == 'M' && x.first != qnt_multi[x.second.first]) {
			pq.push ({qnt_multi[x.second.first], x.second});
			continue;
		}

		// printf("%d %d %c %d\n", x.first, x.second.first, x.second.second, total);
		rem_vert (x.second.first, x.second.second);
		ret++;
	}

	return ret++;
}

int main ()
{
	int x;
	scanf ("%d", &t);
	for (int caso = 1; caso <= t; caso++) {
		// Reset variables/structures
		total = 0;
		for (int i = 0; i < MAXN; i++) {
			qnt_divs[i] = qnt_multi[i] = 0;
			for (int j = 0; j < MAXN; j++)
				adj[i][j] = 0;
		}
		divs.clear(); multi.clear();

		// Possible divisors
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &x);
			divs[i] = x;
		}
		// Possible multiples and counting edges
		scanf ("%d", &m);
		for (int i = 1; i <= m; i++) {
			scanf ("%d", &x);
			multi[i] = x;
			for (pair<int, int> pa : divs) {
				if ((pa.second == 0 && x == 0) || (pa.second && !(x % pa.second))) {
					total++;
					adj[pa.first][i] = true;
					qnt_divs[pa.first]++;
					qnt_multi[i]++;
					// printf ("d: %d\n", qnt_divs[pa.first]);
				}

			}
		}
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf ("%d", adj[i][j]);
				if (j < m) putchar (' ');
			}
			putchar ('\n');
		}*/

		printf ("Case %d: %d\n", caso, rem_edges ());
	}

	return 0;
}
