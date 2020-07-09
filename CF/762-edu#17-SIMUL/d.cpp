#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5+10;
const int INF = -1e18;
int n;
ll mat[6][MAXN];
priority_queue <ll> pq;
int mat_adj[4][2] = {	{1, 0},
						{-1, 0},
						{0, 1},
						{0, -1}	};

void adj (pii p)
{
	int x, y;
	for (int i = 0; i < 4; i++) {
		x = mat_adj[i][0];
		y = mat_adj[i][1];
		if (mat[p.x]
	}
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		mat[4][i] = mat[0][i] = INF;
	for (int i = 0; i < 5; i++)
		mat[n+1][i] = mat[0][i] = -1e18;

	for (int j = 1; j < 4; j++)
		for (int i = 1; i <= n; i++)
			scanf ("%d", mat[j][i]);

	return 0;
}
