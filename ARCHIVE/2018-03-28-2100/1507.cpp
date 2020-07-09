#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int i, j, k;
int n, qnt_m, qnt, pos;
int mat[MAXN][54]; // Pos. 0 → Pos.1 (that way 0 means null). Starts with 'a'
char c, str[MAXN];
bool ans;

void aux (char *c_aux) {
	if (*c_aux >= 'a' && *c_aux <= 'z')
		*c_aux -= 'a';
	else
		*c_aux = *c_aux-'A'+('z'-'a')+1;
}

int main ()
{
	scanf ("%d ", &qnt);
	for (i = 0; i < qnt; i++) {
		scanf ("%s ", str);
		n = strlen (str);
		pos = n;
		while (pos) {
			c = str[pos-1];
			aux (&c);
			for (j = 0; j < 54; j++) {
				if (mat[0][j])
					mat[pos][j] = mat[0][j];
				else
					mat[pos][j] = 0;
			}
			mat[0][c] = pos;
			pos--;
		}
		scanf ("%d ", &qnt_m);
		for (j = 0; j < qnt_m; j++) {
			pos = 0;
			ans = true;
			c = getchar();
			while (ans && c != '\n') {
				//printf ("%c ", c);
				aux (&c);
				if (mat[pos][c])
					pos = mat[pos][c];
				else
					ans = false;
				c = getchar();
			}
			//putchar ('\n');
			while (c != '\n')
				c = getchar();
			ans ? printf ("Yes\n") : printf ("No\n");
		}
		/*for (j = 0; j <= n; j++) {
			//printf ("%2d: ", j);
			for (k = 0; k < 54; k++) {
				//printf ("%2d ", mat[j][k]);
				mat[j][k] = 0;
			}
			//putchar ('\n');
		}*/
		for (j = 0; j < 54; j++)
			mat[0][j] = 0;
	}
	return 0;
}
