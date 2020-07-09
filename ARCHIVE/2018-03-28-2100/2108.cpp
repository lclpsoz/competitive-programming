#include <bits/stdc++.h>
using namespace std;

int i, j;
int mx;
int sizes[110];
char c;
char arr[110];
char maxi[110];

int main ()
{
    c = getchar ();
    while (c != '0' && c != EOF) {
	for (int k = 0; k < 110; k++)
	    sizes[k] = -1;

	j = 0;
	while (c != '\n' && c != '0') {
	    i = 0;
	    while (c != ' ' && c != '\n') {
		arr[i++] = c;
		c = getchar ();
	    }
	    arr[i] = '\0';
	    sizes[j++] = strlen (arr);
	    if (strlen (arr) >= strlen (maxi))
		strcpy (maxi, arr);
	    if (c != '\n')
		c = getchar ();
	}
	int k = 0;
	printf ("%d", sizes[k++]);
	while (sizes[k] != -1)
	    printf ("-%d", sizes[k++]);
	putchar ('\n');
	c = getchar ();
    }

    printf ("\nThe biggest word: %s\n", maxi);

    return 0;
}
