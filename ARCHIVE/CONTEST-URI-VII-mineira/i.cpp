#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e3+10;

int n, m, k, x;
int a, b;
char mat[MAXN][MAXN];
pii aux[MAXN][MAXN];
vector<pii> vec;

bool operator> (pii &p1, pii &p2) {
	if (p1.x >= p2.x && p1.y >= p2.y) return true;
	return false;
}

pii fill () {
	pii maxi = {0, 0};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (mat[i][j] == '.') {
				aux[i][j].x = aux[i-1][j].x+1;
				aux[i][j].y = aux[i][j-1].y+1;
				if (aux[i][j] > maxi)
					maxi = aux[i][j];
			}
	}

	return maxi;
}

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++)
			mat[i][j] = getchar ();
	}
	scanf ("%d", &k);
	while (k--) {
		scanf ("%d %d", &a, &b);
		if (a > b) swap (a, b);
		vec.pb ({a, b});
	}
	sort (vec.begin(), vec.end());

	pii p_max = fill ();

	printf ("%d %d\n", p_max.x, p_max.y);

	return 0;
}
