#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e3+10;

int n, m, k;
pair<int, int> linhas[MAXN];
pair<int, int> cols[MAXN];
int mat[MAXN][MAXN];
int ans[5];

int main ()
{
	char c;
	int x;
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf (" %c %d", &c, &x);
		if (c == 'L')
			linhas[x] = {i+1, (i%4)+1};
		else
			cols[x] = {i+1, (i%4)+1};
	}

	set<pair<pii, pair<char, int>>> s;
	for (int i = 1; i <= n; i++)
			s.insert ({linhas[i], {'L', i}});
	for (int i = 1; i <= m; i++)
			s.insert ({cols[i], {'C', i}});

	/*for (auto p : s)
		if (p.x.x)
			printf ("%d %d %c %d\n", p.x.x, p.x.y, p.y.x, p.y.y);*/
	while (!s.empty()) {
		auto p = *(s.begin());
		s.erase (s.begin());
		if (p.y.x == 'L') {
			for (int i = 1; i <= m; i++) {
				int &aux = mat[p.y.y][i];
				ans[aux]--;
				aux = p.x.y;
				ans[aux]++;
			}
		} else {
			for (int i = 1; i <= n; i++) {
				int &aux = mat[i][p.y.y];
				ans[aux]--;
				aux = p.x.y;
				ans[aux]++;
			}
		}
	}

	printf ("R%d H%d C%d P%d\n", ans[1], ans[2], ans[3], ans[4]);

	return 0;
}
