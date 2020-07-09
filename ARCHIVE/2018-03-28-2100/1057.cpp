#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pair<pii, pair <pii, pii>>,int> ppii;
const int N = 10;

int t, n, ans, z;
bool aux;
bool mat[101][101][101];
char sce[N][N];
char arr[] = {'N', 'E', 'S', 'W'};
queue <ppii> q;
pii a, b, c, a1, b1, c1;

// 0: Invalid
// 1: Valid
// 2: 3 Targets
int valid (char dir)
{
	switch (dir) {
		case 'N':
			if ((!a.first && !b.first && !c.first) || (sce[a.first-1][a.second] != '.' && sce[b.first-1][b.second] != '.' && sce[c.first-1][c.second] != '.')) {
				if (sce[a.first-1][a.second] == 'X' && sce[b.first-1][b.second] == 'X' && sce[c.first-1][c.second] == 'X')
					return 2;
				return 0;
			}
			a1 = a;
			b1 = b;
			c1 = c;
			if (a.first)
				a1.first--;
			if (b.first)
				b1.first--;
			if (c.first)
				c1.first--;
			return 1;
		case 'E':
			if ((a.second == n-1 && b.second == n-1 && c.second == n-1) || (sce[a.first][a.second+1] != '.' && sce[b.first][b.second+1] != '.' && sce[c.first][c.second+1] != '.')) {
				if (sce[a.first][a.second+1] == 'X' && sce[b.first][b.second+1] == 'X' && sce[c.first][c.second+1] == 'X')
					return 2;
				return 0;
			}
			a1 = a;
			b1 = b;
			c1 = c;
			if (a.second < n-1)
				a1.second++;
			if (b.second < n-1)
				b1.second++;
			if (c.second < n-1)
				c1.second++;
			return 1;
		case 'S':
			if ((a.first == n-1 && b.first == n-1 && c.first == n-1) || (sce[a.first+1][a.second] != '.' && sce[b.first+1][b.second] != '.' && sce[c.first+1][c.second] != '.')) {
				if (sce[a.first+1][a.second] == 'X' && sce[b.first+1][b.second] == 'X' && sce[c.first+1][c.second] == 'X')
					return 2;
				return 0;
			}
			a1 = a;
			b1 = b;
			c1 = c;
			if (a.first < n-1)
				a1.first++;
			if (b.first < n-1)
				b1.first++;
			if (c.first < n-1)
				c1.first++;
			return 1;
	}
	// West:
	if (!a.second && !b.second && !c.second && sce[a.first][a.second-1] != '.' && sce[b.first][b.second-1] != '.' && sce[c.first][c.second-1] != '.') {
		if (sce[a.first][a.second-1] == 'X' && sce[b.first][b.second-1] == 'X' && sce[c.first][c.second-1] == 'X')
			return 2;
		return 0;
	}
	a1 = a;
	b1 = b;
	c1 = c;
	if (a.second)
		a1.second--;
	if (b.second)
		b1.second--;
	if (c.second)
		c1.second--;
	return 1;
}

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d", &n);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				scanf (" %c", &sce[j][k]);
				if (sce[j][k] == 'A') {
					a.first = j;
					a.second = k;
				}
				else if (sce[j][k] == 'B') {
					b.first = j;
					b.second = k;
				}
				else if (sce[j][k] == 'C') {
					c.first = j;
					c.second = k;
				}
			}

		// BFS
		q.push ({{a, {b, c}}, 0});
		ans = -1;
		while (!q.empty ()) {
			a = q.front().first.first;
			b = q.front().first.second.first;
			c = q.front().first.second.second;
			z = q.front().second;
			mat[(a.first*10) + a.second][(b.first*10) + b.second][(c.first*10) + c.second] = true;
			printf ("%d %d\n", a.first, a.second);
			for (char i : arr) {
					aux = valid (i);
					printf ("%c: %d\n", i, aux);
					if (aux == 2) {
						ans = q.front().second;
						break;
					}
					else if (aux) {
						if (!mat[(a1.first*10) + a1.second][(b1.first*10) + b1.second][(c1.first*10) + c1.second])
							q.push ({{a1, {b1, c1}}, z+1});
					}
			}
			q.pop ();
		}
		while (!q.empty ())
			q.pop ();
		printf ("Caso %d: ", i+1);
		if (ans == -1)
			printf ("trapped\n");
		else
			printf ("%d\n", ans);

		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				for (int l = 0; l < 101; l++)
					mat[j][k][l] = false;

	}

	return 0;
}
