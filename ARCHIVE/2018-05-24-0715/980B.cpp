#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n, k;
char mat[5][110];

int main ()
{
	scanf ("%d %d", &n, &k);
	printf ("YES\n");
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = '.';

	if (k&1) {
		int i = n/2;
		int j = 0;
		while (i && k > 0) {
			mat[1][i] = '#'; k--;
			i += j++;
			mat[1][i] = '#'; k--;
			i -= j++;
		}
		i = 1;
		j = n-3;
		k++;
		// printf ("%d\n", k);
		while (k) {
			k-=2;
			mat[2][i] = '#';
			i+=j--;
			mat[2][i] = '#';
			i-=j--;
		}
	} else {
		int i = 1;
		while (k) {
			k-=2;
			mat[1][i] = mat[2][i] = '#';
			i++;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++)
			putchar (mat[i][j]);
		putchar ('\n');
	}


	return 0;
}
