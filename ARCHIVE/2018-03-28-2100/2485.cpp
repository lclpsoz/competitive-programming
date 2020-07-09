#include <bits/stdc++.h>
using namespace std;

int qnt;
int mat[105][105];
int n, m;
int x, y;
queue<pair<pair<int,int>, int>> q;

int main ()
{
	scanf ("%d", &qnt);
	for (int i = 0; i < qnt; i++) {
		scanf ("%d %d", &n, &m);
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= m; k++)
				scanf ("%d", &mat[j][k]);
		scanf ("%d %d", &x, &y);
		q.push ({{x, y}, 0});
		mat[x][y] = 0;
		int ans = -1;
		while (!q.empty ()) {
			ans = q.front ().second;
			x = q.front ().first.first-1;
			y = q.front ().first.second-1;
			q.pop ();
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					if (mat[x+j][y+k]) {
						//printf ("%d %d\n", x+j, y+k);
						mat[x+j][y+k] = 0;
						q.push ({{x+j, y+k}, ans+1});
					}
		}
		for (int j = 0; j < 105; j++)
			for (int k = 0; k < 105; k++)
				mat[j][k] = 0;

		printf ("%d\n", ans);
	}

	return 0;
}
