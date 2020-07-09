#include <bits/stdc++.h>
using namespace std;

int i, j, k;
int ans;
char a[20], b[20], bigi[20], smal[20];

int main ()
{
	while (scanf ("%s %s", a, b), a[0] != '0' || b[0] != '0') {
		if (strlen (a) > strlen (b)) {
			strcpy (bigi, a);
			strcpy (smal, b);
		}
		else {
			strcpy (bigi, b);
			strcpy (smal, a);
		}
		i = strlen (bigi) - 1;
		j = strlen (smal) - 1;
		ans = 0;
		for (;j >= 0; j--, i--) {
			if (((bigi[i]-'0') + (smal[j]-'0')) > 9) {
				ans++;
				if (i > 0)
					bigi[i-1]++;
			}
		}
		for (; i >= 0; i--)
			if (bigi[i] > '9') {
				ans++;
				if (i > 0)
					bigi[i-1]++;
			}
		if (ans > 1)
			printf ("%d carry operations.\n", ans);
		else if (ans)
			printf ("%d carry operation.\n", ans);
		else
			printf ("No carry operation.\n");
	}

	return 0;
}
