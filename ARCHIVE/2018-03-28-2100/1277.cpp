#include <bits/stdc++.h>
using namespace std;

int t, n;
int p, total;
char mat1[105][60];
char mat2[105][60];

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t;i++) {
		scanf ("%d", &n);
		for (int j = 0; j < n; j++)
			scanf (" %s ", mat1[j]);
		for (int j = 0; j < n; j++)
			scanf (" %s ", mat2[j]);

		bool bef = false;
		for (int j = 0; j < n; j++) {
			for (int k = 0; mat2[j][k] != '\0'; k++) {
				if (mat2[j][k] == 'P') {
					total++;
					p++;
				}
				else if (mat2[j][k] == 'A')
					total++;
			}
			if (p < (3*total/4.0)) {
				if (bef)
					putchar (' ');
				bef = true;
				printf ("%s", mat1[j]);
			}
			p = total = 0;
		}
		putchar ('\n');

	}
	return 0;
}
