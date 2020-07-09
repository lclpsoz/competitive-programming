#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

char mat[5][5];

int x, y;

int main ()
{
	int n, m;
	scanf ("%d %d ", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			x = (i%3)+1;
			y = (j%3)+1;
			mat[x][y] = getchar();
			if (
		}
		getchar ();
	}

	return 0;
}
