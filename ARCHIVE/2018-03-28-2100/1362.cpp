#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int arr[100], shirts[6];
char sizes[][4] = {"XXL", "XL", "L", "M", "S", "XS"};
char aux1[5], aux2[5];

bool dfs (int x)
{
	/*printf ("%d:\n", x);
	for (int a : shirts)
		printf ("%d ", a);
	putchar ('\n');*/
	if (x == m)
		return true;
	bool ans = false;
	for (int i = 0; i < 6 && !ans; i++)
		if ((arr[x] & 1<<i) && shirts[i]) {
			shirts[i]-=1;
			ans = dfs (x+1);
			shirts[i]+=1;
		}

	return ans;
}

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &m);
		for (int i = 0; i < 6; i++)
			shirts[i] = n/6;
		for (int i = 0; i < m; i++) {
			scanf ("%s %s", aux1, aux2);
			arr[i] = 0;
			for (int j = 0; j < 6; j++)
				if (!strcmp (aux1, sizes[j]) || !strcmp (aux2, sizes[j]))
					arr[i] |= 1<<j;
			//printf ("%d\n", arr[i]);
		}

		dfs (0) ? printf ("YES\n") : printf ("NO\n");
		// printf ("_____________________________________________________\n");
	}

	return 0;
}
