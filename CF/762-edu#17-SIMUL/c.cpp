#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;

char a[MAXN];
char b[MAXN];
int mat[MAXN][32];

int main ()
{
	scanf ("%s %s", a, b);
	int maxi = 'z'-'a';
	for (int i = strlen (a)-2; i >= 0; i--) {
		for (int j = 0; j <= maxi; j++)
			mat[i][j] = mat[i+1][j];
		mat[i][a[i+1]-'a'] = i+1;
	}
	for (int j = 0; j < strlen(a); j++) {
		printf ("%c: ", a[j]);
		for (int i = 0; i <= maxi; i++)
			printf ("%2d ", mat[j][i]);
		putchar ('\n');
	}

	// Exclude:
	int st, en;
	st = en = -1;
	// Ans:
	int comec, fim;
	comec = 0;
	fim = strlen (b)-1;

	int max_b = fim+1;
	int max_a = strlen (a);
	int j = 0;
	for (int i = 0; j < max_a && i < max_b;) {
		if (b[i] == a[j]) {
			i++;
			j++;
		}
		else {
			if (mat[j][b[i]-'a'] != 0) {
				j = mat[j][b[i]-'a']+1;
				i++;
			} else {
				if (st == -1) st = i;
				en = i;
				i++;
			}
		}

	}
	return 0;
}
