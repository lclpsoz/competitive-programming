#include <bits/stdc++.h>
using namespace std;

typedef struct coord {
	int x, y;
} cd;

typedef pair<int, cd> pic;
const int MAXN = 1010;

int n, m, k, w;
char mat[MAXN][MAXN];
cd st, en;
// priority_queue<pic, vector<pic>, greater<pic>> pq;
queue <pic> q;

void paths (int x, int y)
{
	for (int i = 1; i <= k; i++) {
		if (mat[x-i][y] == '.') {
			q.push ({w+1, {x-i, y}});
			mat[x-i][y] = '-';
		}
		else if (mat[x-i][y] == '#')
			break;
	}
	for (int i = 1; i <= k; i++) {
		if (mat[x][y+i] == '.') {
			q.push ({w+1, {x, y+i}});
			mat[x][y+i] = '-';
		}
		else if (mat[x][y+i] == '#')
			break;
	}
	for (int i = 1; i <= k; i++) {
		if (mat[x+i][y] == '.') {
			q.push ({w+1, {x+i, y}});
			mat[x+i][y] = '-';
		}
		else if (mat[x+i][y] == '#')
			break;
	}
	for (int i = 1; i <= k; i++) {
		if (mat[x][y-i] == '.') {
			q.push ({w+1, {x, y-i}});
			mat[x][y-i] = '-';
		}
		else if (mat[x][y-i] == '#')
			break;
	}
}

int main ()
{
	scanf ("%d %d %d ", &n, &m, &k);
	for (int i = 0; i <= m+1; i++)
		mat[0][i] = '#'; // SUPERIOR BORDER
	for (int i = 1; i <= n; i++) {
		mat[i][0] = '#'; // LEFT BORDER
		for (int j = 1; j <= m; j++) {
			mat[i][j] = getchar ();
			// putchar (mat[i][j]);
		}
		getchar ();
		// putchar ('\n');
		mat[i][m+1] = '#'; // RIGHT BORDER
	}
	for (int i = 0; i <= m+1; i++)
		mat[n+1][i] = '#'; // INFERIOR BORDER
	/*for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++)
			putchar (mat[i][j]); putchar ('\n');}*/

	scanf ("%d %d %d %d", &st.x, &st.y, &en.x, &en.y);
	q.push ({0, st});
	// printf ("%d %d\n", q.front().second.x, q.front().second.y);
	while (!q.empty () && (q.front ().second.x != en.x || q.front().second.y != en.y)) {
		w = q.front().first;
		cd aux = q.front().second;
		q.pop ();
		// printf ("%d (%d, %d)\n", w, aux.x, aux.y);
		paths (aux.x, aux.y);
	}

	if (q.empty ())
		printf ("-1\n");
	else
		printf ("%d\n", q.front().first);

	return 0;
}
