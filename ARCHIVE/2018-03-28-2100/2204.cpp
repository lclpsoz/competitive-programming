#include <bits/stdc++.h>
using namespace std;

int t;
char str1[110], str2[110];

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s %s", str1, str2);
		if (strcmp (str1, str2) == 0)
			printf (str1);
		else
			printf ("1\n");
	}

	return 0;
}
