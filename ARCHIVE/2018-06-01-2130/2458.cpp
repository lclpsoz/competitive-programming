#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;
char mat[505][505];
char info[505][505];

char dfs (int i, int j) {
	//printf ("%d %d %c\n", i, j, info[i][j]);
	if (info[i][j] == 'X' || mat[i][j] == '\0') return 'X';
	else if (info[i][j] == '\0') {
		info[i][j] = '?';
		//printf (" -\n");
		switch (mat[i][j]) {
			case '>':
				info[i][j] = dfs (i, j+1);
				break;
			case 'V':
				info[i][j] = dfs (i+1, j);
				break;
			case '<':
				info[i][j] = dfs (i, j-1);
				break;
			case 'A':
				info[i][j] = dfs (i-1, j);
				break;
		}
		//printf (" %c\n", info[i][j]);
		return info[i][j];
	} else
		return 'S';
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		getchar ();
		for (int j = 1; j <= n; j++)
			mat[i][j] = getchar ();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			//printf ("[%c]\n", mat[i][j]);
			if (info[i][j] == '\0')
				info[i][j] = dfs (i, j);
			//printf ("%c\n", info[i][j]);
			if (info[i][j] == 'S')
				ans++;
		}

	printf ("%d\n", ans);

	return 0;
}
