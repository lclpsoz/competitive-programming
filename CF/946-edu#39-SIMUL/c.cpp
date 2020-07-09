#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

char arr[MAXN];
char alp[] = {"abcdefghijklmnopqrstuvwxyz"};

int main ()
{
	scanf ("%s", arr);
	if (strlen (arr) < 26)
		printf ("-1\n");
	else {
		int i, j;
		for (i = j = 0; arr[i] != '\0' && alp[j] != '\0'; i++)
			if (arr[i] <= alp[j]) {
				arr[i] = alp[j];
				j++;
			}
		if (alp[j] == '\0') {
			printf ("%s\n", arr);
		} else {
			printf ("-1\n");
		}
	}

	return 0;
}
