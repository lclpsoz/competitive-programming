#include <bits/stdc++.h>
using namespace std;

int n;
int maxi;
char mat[105][60], arr[60];

int main ()
{
	bool t = false;
	while (scanf ("%d", &n), n) {
		if (t)
			putchar ('\n');
		int k;
		maxi = 0;
		for (int i = 0; i < n; i++) {
			scanf (" %[^\n]", arr);
			k = 0;
			char *aux = strtok (arr, " ");
			while (aux != NULL) {
				if (k)
					mat[i][k++] = ' ';
				for (int j = 0; aux[j] != '\0'; j++)
					mat[i][k++] = aux[j];

				aux = strtok (NULL, " ");
			}
			mat[i][k] = '\0';
			maxi = max (maxi, (int) strlen (mat[i]));
		}
		t = true;
		for (int i = 0; i < n; i++)
			printf ("%*s\n", maxi, mat[i]);
	}

	return 0;
}
