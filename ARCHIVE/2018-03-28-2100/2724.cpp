#include <bits/stdc++.h>
using namespace std;

int t, n, t1;
char arr[55], mat[55][55], *p;
bool ans;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &t1);
		for (int j = 0; j < t1; j++) {
			scanf ("%s", arr);
			strcpy (mat[j], arr);
		}
		scanf ("%d", &t);
		for (int j = 0; j < t; j++) {
			scanf ("%s", arr);
			ans = false;
			for (int k = 0; k < t1; k++) {
				p = strstr (arr, mat[k]);
				if (p != NULL) {
					if ((p[strlen(mat[k])] == '\0') || (p[strlen(mat[k])] >= 'A' && p[strlen(mat[k])] <= 'Z'))
						ans = true;
				}
			}
			ans ? printf ("Abortar\n") : printf ("Prossiga\n");
		}
		if (i < n-1)
			putchar ('\n');
	}
	return 0;
}
