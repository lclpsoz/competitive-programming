#include <bits/stdc++.h>
using namespace std;

int t, l, c, pos, n, ans, aux[30];
char mat[52][52], str[6000], *aux1, *aux2, arr[6000];

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		pos = 0;
		scanf ("%d %d", &l, &c);
		for (int j = 0; j < l; j++) {
			for (int k = 0; k < c; k++) {
				scanf (" %c", &mat[j][k]);
				aux[mat[j][k]-'a']++;
				str[pos++] = mat[j][k];
			}
			str[pos++] = ' ';
		}
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < l; k++) {
				str[pos++] = mat[k][j];
			}
			str[pos++] = ' ';
		}
		str[pos] = '\0';
		//printf ("%s\n", str);
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			ans = 0;
			scanf (" %[^\n]", arr);
			if (strlen(arr) == 1)
				ans = aux[arr[0]-'a'];
			else {
				aux1 = strstr (str, arr);
				while (aux1 != NULL) {
					ans++;
					aux1 = strstr (aux1+1, arr);
				}
			}
			printf ("%d\n", ans);
		}
		for (int i = 0; i < 30; i++)
			aux[i] = 0;
	}
	return 0;
}
